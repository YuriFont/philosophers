/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:27 by yufonten          #+#    #+#             */
/*   Updated: 2024/03/14 10:56:33 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mut;

typedef struct s_philo
{
	int		id;
	int		n_eats;
}	t_philo;

typedef struct s_fork
{
	t_mut	fork;
	int	fork_id;
}	t_fork;

typedef struct s_sapien
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	t_philo	*philos;
}	t_sapien;

int	ft_atoi(char *str);
int	check_num_argv(int ac);

#endif
