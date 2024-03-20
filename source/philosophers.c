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

int	main(int ac, char **av)
{
	t_sapien	p;

	if (check_num_argv(ac))
		return (1);
	if (check_args(&p, av))
		return (1);
	return (0);
}
