/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:17 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 13:29:25 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clean_exit(t_sapien *s)
{
	int	i;

	i = 0;
	while (i < s->n_philo)
	{
		handle_mutex(&s->philos[i].p_mut, DESTROY);
		handle_mutex(&s->forks[i].fork, DESTROY);
		i++;
	}
	handle_mutex(&s->w_mut, DESTROY);
	handle_mutex(&s->write, DESTROY);
	free(s->philos);
	free(s->forks);
}

int	main(int ac, char **av)
{
	t_sapien	s;

	if (check_num_argv(ac) || check_args(ac, av))
		return (1);
	if (init_dining(&s, av))
		return (1);
	if (start(&s))
		return (1);
	clean_exit(&s);
	return (0);
}
