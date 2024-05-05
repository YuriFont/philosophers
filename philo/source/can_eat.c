/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:07 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 15:04:30 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*fight_forks(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set(&p->p_mut, &p->s->e_arrive,
		(get(&p->p_mut, &p->s->e_arrive) + 1));
	wait_everyone(p->s);
	set(&p->p_mut, &p->l_teat, get_time(MILLISECONDS));
	while (!get(&p->p_mut, &p->s->end_d))
	{
		if (p->satisfied)
			break ;
		eat(p);
		sleeping(p);
		write_status(THINKING, p);
	}
	return (NULL);
}

int	start(t_sapien *s)
{
	int	i;

	i = 0;
	if (s->n_eats == 0)
		return (0);
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