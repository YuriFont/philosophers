/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:31 by yufonten          #+#    #+#             */
/*   Updated: 2024/04/09 11:08:06 by yufonten         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	if (measure == 'S')
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (measure == 'L')
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (measure == 'C')
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	return (42);
}
