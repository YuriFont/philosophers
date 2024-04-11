/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:07 by yufonten          #+#    #+#             */
/*   Updated: 2024/04/11 20:38:02 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_everyone(t_sapien *s)
{
	while (!get(&s->w_mut, &s->e_arrive))
		;
}

void	*fight_forks(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_everyone(philo->s);
	while (!get(&philo->s->w_mut, philo->s->end_d))
	{

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
	set(&s->w_mut, &s->e_arrive, TRUE);
	i = 0;
	while (i < s->n_philo)
		handle_thread(&s->philos[i++].thread, NULL, NULL, JOIN);
	return (0);
}