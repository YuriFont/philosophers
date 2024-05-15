/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:07 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/15 14:42:34 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*alone_dinning(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set(&p->p_mut, &p->l_teat, get_time(MILLISECONDS));
	write_status(TAKE_FIRST_FORK, p);
	while (!get(&p->p_mut, &p->s->end_d))
		usleep(300);
	return (NULL);
}

static void	*fight_forks(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set(&p->p_mut, &p->l_teat, get_time(MILLISECONDS));
	set(&p->s->w_mut, &p->s->e_arrive,
		(get(&p->s->w_mut, &p->s->e_arrive) + 1));
	wait_everyone(p->s);
	while (!get(&p->s->w_mut, &p->s->end_d))
	{
		if (p->satisfied)
			break ;
		eat(p);
		sleeping(p);
		thinking(p);
	}
	return (NULL);
}

void	start(t_sapien *s)
{
	int			i;

	i = -1;
	if (s->n_eats == 0)
		return ;
	else if (s->n_philo == 1)
	{
		s->s_simulation = get_time(MILLISECONDS);
		handle_thread(&s->philos[0].thread, alone_dinning,
			&s->philos[0], CREATE);
	}
	else
	{
		s->s_simulation = get_time(MILLISECONDS);
		while (++i < s->n_philo)
			handle_thread(&s->philos[i].thread, fight_forks,
				&s->philos[i], CREATE);
	}
	handle_thread(&s->monitor, ethic_at_dinner, s, CREATE);
	set(&s->w_mut, &s->e_arrive, TRUE);
	i = -1;
	while (++i < s->n_philo)
		handle_thread(&s->philos[i].thread, NULL, NULL, JOIN);
	set(&s->w_mut, &s->end_d, TRUE);
	handle_thread(&s->monitor, NULL, NULL, JOIN);
}
