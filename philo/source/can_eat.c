/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:07 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 13:28:59 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_everyone(t_sapien *s)
{
	while (get(&s->w_mut, &s->e_arrive) < s->n_philo)
		;
}

void	ethic_at_dinner(t_sapien *s)
{
	int	i;

	if (get(&s->w_mut, &s->e_arrive) != s->n_philo)
		return (error("Error creating threads."));
	while (!dinner_is_over(s))
	{
		i = 0;
		while (i < s->n_philo)
		{
			if (philo_died(&s->philos[i]))
			{
				set(&s->w_mut, &s->end_d, TRUE);
				write_status(DIED, &s->philos[i]);
				return ;
			}
			i++;
		}
	}
}

void	eat(t_philo *philo)
{
	handle_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	philo->l_teat = get_time(MILLISECONDS);
	philo->n_eats++;
	write_status(EATING, philo);
	usleep(philo->s->t_eat);
	if (philo->s->n_eats > 0 && philo->n_eats == philo->s->n_eats)
		philo->satisfied = TRUE;
	handle_mutex(&philo->first_fork->fork, UNLOCK);
	handle_mutex(&philo->second_fork->fork, UNLOCK);
}

void	*fight_forks(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set(&p->p_mut, &p->s->e_arrive,
		(get(&p->p_mut, &p->s->e_arrive) + 1));
	wait_everyone(p->s);
	while (!get(&p->p_mut, &p->s->end_d))
	{
		if (p->satisfied)
			break ;
		eat(p);
		write_status(SLEEPING, p);
		usleep(p->s->t_sleep);
		write_status(THINKING, p);
		ethic_at_dinner(p->s);
	}
	return (NULL);
}

int	start(t_sapien *s)
{
	int	i;

	i = 0;
	if (s->n_eats == 0)
		return (1);
	else if (s->n_philo == 1)
		return (1);
	else
	{
		s->s_simulation = get_time(MILLISECONDS);
		while (i < s->n_philo)
		{
			handle_thread(&s->philos[i].thread, fight_forks, &s->philos[i], CREATE);
			i++;
		}
	}
	i = 0;
	while (i < s->n_philo)
		handle_thread(&s->philos[i++].thread, NULL, NULL, JOIN);
	return (0);
}