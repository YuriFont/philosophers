/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/25 20:38:15 by yufonten         ###   ########.fr       */
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

int	check_args(char **av)
{
	int	len;

	if (ft_atoi(av[1]) < 1)
		return (1);
	if (ft_atoi(av[2]) < 0)
		return (1);
	if (ft_atoi(av[3]) < 0)
		return (1);
	if (ft_atoi(av[4]) < 0)
		return (1);
	len = ft_strlen(av[5]) - 1;
	if (av[5] != NULL && (av[5][0] != '[' || av[5][len] != ']'))
		return (1);
	if (av[5] != NULL && ft_atoi(av[5]) < 0)
		return (1);
	return (0);
}
