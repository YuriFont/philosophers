/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:17 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/14 11:33:11 by yufonten         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	(void)av;
	if (check_num_argv(ac))
		return (1);
	printf("Foi.\n");
	return (0);
}
