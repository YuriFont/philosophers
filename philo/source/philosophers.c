/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:17 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/29 20:54:56 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_sapien	s;

	if (check_num_argv(ac) || check_args(ac, av))
		return (1);
	if (init_dining(&s, av))
		return (1);
	if (can_eat())
	{
		
	}
	return (0);
}
