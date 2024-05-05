/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:44:08 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 13:47:32 by yufonten         ###   ########.fr       */
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