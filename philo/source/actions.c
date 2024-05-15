/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:44:08 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/15 14:28:06 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo *philo)
{
	handle_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	philo->n_eats++;
	write_status(EATING, philo);
	usleep(philo->s->t_eat);
	set(&philo->p_mut, &philo->l_teat, get_time(MILLISECONDS));
	if (philo->s->n_eats > 0 && philo->n_eats == philo->s->n_eats)
		set(&philo->p_mut, &philo->satisfied, TRUE);
	handle_mutex(&philo->first_fork->fork, UNLOCK);
	handle_mutex(&philo->second_fork->fork, UNLOCK);
}

void	sleeping(t_philo *p)
{
	write_status(SLEEPING, p);
	usleep(p->s->t_sleep);
}

void	thinking(t_philo *p)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	write_status(THINKING, p);
	if (p->s->n_philo % 2 == 0)
		return ;
	t_eat = p->s->t_eat;
	t_sleep = p->s->t_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	usleep(t_think * 0.42);
}

void	*ethic_at_dinner(void *arg)
{
	int			i;
	t_sapien	*s;

	s = (t_sapien *)arg;
	while (!get(&s->w_mut, &s->end_d))
	{
		i = 0;
		while (i < s->n_philo && !get(&s->w_mut, &s->end_d))
		{
			if (philo_died(&s->philos[i]))
			{
				set(&s->w_mut, &s->end_d, TRUE);
				write_status(DIED, &s->philos[i]);
			}
			i++;
		}
	}
	return (NULL);
}

void	wait_everyone(t_sapien *s)
{
	while (get(&s->w_mut, &s->e_arrive) == FALSE)
		;
}
