/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:17 by yufonten          #+#    #+#             */
/*   Updated: 2024/04/10 10:36:13 by yufonten         ###   ########.fr       */
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
	if (start(&s))
		return (1);
	free(s.philos);
	free(s.forks);
	return (0);
}
