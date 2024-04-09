/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:07 by yufonten          #+#    #+#             */
/*   Updated: 2024/04/09 11:24:56 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_everyone(t_sapien *s)
{
	while (!(int)get(&s->w_mut, (long)&s->e_arrive))
		;
}

void	*fight_forks(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_everyone(philo->s);
	return (NULL);
}

int	start(t_sapien *s)
{
	int	i;

	i = 0;
	if (s->n_eats == 0)
		return ;
	else if (s->n_philo == 1)
		return ;
	else
	{
		while (i < s->n_philo)
		{
			handle_thread(&s->philos[i].id, fight_forks, &s->philos[i], CREATE);
			i++;
		}
	}
	set(&s->w_mut, &s->e_arrive, TRUE);
	s->s_simulation = get_time('L');
	i = 0;
	while (i < s->n_philo)
		handle_thread(&s->philos[i++].thread, NULL, NULL, JOIN);
}