/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:22:18 by yufonten          #+#    #+#             */
/*   Updated: 2024/04/09 11:24:33 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_thread(pthread_t *thread, void *(*ft)(void *), t_sapien *s, char op)
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
