/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/25 21:38:05 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_num_argv(int ac)
{
	if (ac < 5)
	{
		printf("Error: few arguments\n");
		return (1);
	}
	else if (ac > 6)
	{
		printf("Error: many arguments\n");
		return (1);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ft_atol(av[1]) < 1)
		return (throw_error("The number of philosophers must be at least 1"));
	if (ft_atol(av[2]) < 0)
		return (throw_error("Time to die cannot be negative"));
	if (ft_atol(av[3]) < 0)
		return (throw_error("Time to eat cannot be negative"));
	if (ft_atol(av[4]) < 0)
		return (throw_error("Time to sleep cannot be negative"));
	if (ac == 6)
	{
		if (av[5] != NULL && ft_atol(av[5]) < 0)
			return (throw_error("The number of times each philosopher must eat cannot be negative"));
	}
	return (0);
}
