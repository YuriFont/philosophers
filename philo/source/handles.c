/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:22:18 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/05 13:12:27 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_thread(pthread_t *thread, void *(*ft)(void *), void *s, char op)
{
	if (CREATE == op)
		pthread_create(thread, NULL, ft, s);
	else if (JOIN == op)
		pthread_join(*thread, NULL);
	else if (DETACH == op)
		pthread_detach(*thread);
	else
		return (error("Wrong option char in handle_thread"));
	return (0);
}

int	handle_mutex(t_mut *mutex, char op)
{
	if (INIT == op)
		pthread_mutex_init(mutex, NULL);
	else if (LOCK == op)
		pthread_mutex_lock(mutex);
	else if (UNLOCK == op)
		pthread_mutex_unlock(mutex);
	else if (DESTROY == op)
		pthread_mutex_destroy(mutex);
	else
		return (error("Wrong option char in handle_mutex"));
	return (0);
}

void	set(t_mut *mut, long *dst, long value)
{
	handle_mutex(mut, LOCK);
	*dst = value;
	handle_mutex(mut, UNLOCK);
}

long	get(t_mut *mut, long *src)
{
	long	r;

	handle_mutex(mut, LOCK);
	r = *src;
	handle_mutex(mut, UNLOCK);
	return (r);
}

long	philo_died(t_philo *p)
{
	long	elapsed_time;
	long	time_to_died;

	if (get(&p->p_mut, &p->satisfied))
		return (FALSE);
	elapsed_time = get_time(MILLISECONDS) - p->l_teat;
	time_to_died = p->s->t_die / 1000;
	if (elapsed_time >= time_to_died)
		return (TRUE);
	return (FALSE);
}
