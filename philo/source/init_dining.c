/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dining.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:39:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/26 21:02:40 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	filling_sapien(t_sapien *s, char **av)
{
	s->n_philo = ft_atol(av[1]);
	s->t_die = ft_atol(av[2]) * 1000;
	s->t_eat = ft_atol(av[3]) * 1000;
	s->t_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		s->n_eats = ft_atol(av[5]);
	else
		s->n_eats = FALSE;
	s->end_d = FALSE;
}

int	init_dining(t_sapien *s, char **av)
{
	filling_sapien(s, av);
	s->philos = malloc(sizeof(t_philo) * (s->n_philo));
	if (!s->philos)
		return (error("Error in philos malloc"));
	s->forks = malloc(sizeof(t_fork) * (s->n_philo));
	if (!s->forks)
		return (error("Error in forks malloc"));
	
}
