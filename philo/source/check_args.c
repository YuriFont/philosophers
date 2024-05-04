/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/05/04 12:11:44 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		*s++;
	}
	return (1);
}

int	check_num_argv(int ac)
{
	if (ac < 5)
		return (error("Few arguments"));
	else if (ac > 6)
		return (error("Many arguments"));
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ft_atol(av[1]) < 1 || ft_atol(av[1]) > INT_MAX)
		return (error("Parameter error"));
	if (ft_atol(av[2]) <= 0 || ft_atol(av[2]) > INT_MAX)
		return (error("Parameter error"));
	if (ft_atol(av[3]) <= 0 || ft_atol(av[3]) > INT_MAX)
		return (error("Parameter error"));
	if (ft_atol(av[4]) <= 0 || ft_atol(av[4]) > INT_MAX)
		return (error("Parameter error"));
	if (ac == 6)
	{
		if (ft_atol(av[5]) < 0 || ft_atol(av[5]) > INT_MAX)
			return (error("Parameter error"));
	}
	return (0);
}
