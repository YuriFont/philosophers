/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:22:18 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/26 21:30:00 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int handle_thread(pthread_t *thread, void *(*ft)(void *), t_sapien *s,char op)
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