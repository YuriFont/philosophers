/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dining.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:39:12 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/26 22:51:03 by yufonten         ###   ########.fr       */
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

int	init_forks(t_sapien *s)
{
	int	i;

	i = 0;
	while (i < s->n_philo)
	{
		if (handle_mutex(&s->forks[i].fork, INIT))
			return (1);
		i++;
	}
	return (0);
}

void	receiving_forks(t_philo *p, t_fork *forks, int pos)
{
	int	n_philo;

	n_philo = p->s->n_philo;
	if (p->id %2 != 0)
	{
		p->l_fork = &forks[(pos + 1) % n_philo];
		p->r_fork = &forks[pos];
	}
	if (p->id % 2 == 0)
	{
		p->r_fork = &forks[pos];
		p->l_fork = &forks[(pos + 1) % n_philo];
	}
}

void	init_philo(t_sapien *s)
{
	int	i;

	i = 0;
	while (i < s->n_philo)
	{
		s->philos[i].s = s;
		s->philos[i].id = i + 1;
		s->philos[i].satisfied = FALSE;
		s->philos[i].n_eats = 0;
		receiving_forks(&s->philos[i], s->forks, i);
		i++;
	}
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
	if (init_forks(s))
		return (1);
	init_philo(s);
	return (0);
}
