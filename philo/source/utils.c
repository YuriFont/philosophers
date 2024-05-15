/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:31 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/15 14:28:29 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

int	error(char *s)
{
	printf("Error:\n");
	printf("%s\n", s);
	return (1);
}

long	get_time(char measure)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (measure == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (measure == MILLISECONDS)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (measure == MICROSECONDS)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	return (42);
}

void	write_status(t_status s, t_philo *p)
{
	long	current_time;

	if (p->satisfied)
		return ;
	current_time = get_time(MILLISECONDS);
	handle_mutex(&p->s->write, LOCK);
	if ((s == TAKE_FIRST_FORK || s == TAKE_SECOND_FORK)
		&& !get(&p->s->w_mut, &p->s->end_d))
		printf("%ld %d has taken a fork\n",
			(current_time - p->s->s_simulation), p->id);
	else if (s == EATING && !get(&p->s->w_mut, &p->s->end_d))
		printf("%ld %d is eating\n",
			(current_time - p->s->s_simulation), p->id);
	else if (s == SLEEPING && !get(&p->s->w_mut, &p->s->end_d))
		printf("%ld %d is sleeping\n",
			(current_time - p->s->s_simulation), p->id);
	else if (s == THINKING && !get(&p->s->w_mut, &p->s->end_d))
		printf("%ld %d is thinking\n",
			(current_time - p->s->s_simulation), p->id);
	else if (s == DIED)
		printf("%ld %d died\n", (current_time - p->s->s_simulation), p->id);
	handle_mutex(&p->s->write, UNLOCK);
}
