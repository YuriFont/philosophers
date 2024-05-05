/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:07 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 16:01:13 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*alone_dinning(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set(&p->p_mut, &p->l_teat, get_time(MILLISECONDS));
	write_status(TAKE_FIRST_FORK, p);
	while (!get(&p->p_mut, &p->s->end_d))
		usleep(300);
	return (NULL);
}

void	*fight_forks(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	set(&p->p_mut, &p->l_teat, get_time(MILLISECONDS));
	set(&p->p_mut, &p->s->e_arrive,
		(get(&p->p_mut, &p->s->e_arrive) + 1));
	wait_everyone(p->s);
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
	s->s_simulation = get_time(MILLISECONDS);
	if (s->n_eats == 0)
		return (0);
	else if (s->n_philo == 1)
		handle_thread(&s->philos[0].thread, alone_dinning,
			&s->philos[0], CREATE);
	else
		while (i < s->n_philo)
		{
			handle_thread(&s->philos[i].thread,
				fight_forks, &s->philos[i], CREATE);
				i++;
		}
	usleep(100);
	handle_thread(&s->monitor, ethic_at_dinner, s, CREATE);
	i = 0;
	while (i < s->n_philo)
		handle_thread(&s->philos[i++].thread, NULL, NULL, JOIN);
	set(&s->w_mut, &s->end_d, TRUE);
	handle_thread(&s->monitor, NULL, NULL, JOIN);
	return (0);
}