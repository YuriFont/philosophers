/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:35 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/26 21:29:31 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int handle_mutex(t_mut *mutex, char op)
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