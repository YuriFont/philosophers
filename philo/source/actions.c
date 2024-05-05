/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:44:08 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 15:04:58 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void    sleeping(t_philo *p)
{
    write_status(SLEEPING, p);
    usleep(p->s->t_sleep);
}

void	ethic_at_dinner(t_sapien *s)
{
	int	i;

	while (!get(&s->w_mut, &s->end_d))
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

void	wait_everyone(t_sapien *s)
{
	while (get(&s->w_mut, &s->e_arrive) < s->n_philo)
		;
}