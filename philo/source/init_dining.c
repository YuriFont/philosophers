#include "philosophers.h"

void	init_diningg(t_sapien *s, char **av)
{
	s->n_philo = ft_atol(av[1]);
	s->t_die = ft_atol(av[2]) * 1000;
	s->t_eat = ft_atol(av[3]) * 1000;
	s->t_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		s->n_eats = ft_atol(av[5]);
	else
		s->n_eats = FALSE;
}
