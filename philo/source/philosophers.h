/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:27 by yufonten          #+#    #+#             */
/*   Updated: 2024/04/12 00:11:17 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define LOCK 'l'
# define UNLOCK 'u'
# define INIT 'i'
# define DESTROY 'd'
# define CREATE 'c'
# define JOIN 'j'
# define DETACH 'd'
# define MILLISECONDS 'L'
# define MICROSECONDS 'C'
# define SECONDS 'S'

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mut;
typedef struct s_sapien t_sapien;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_status;

typedef struct s_fork
{
	t_mut	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		n_eats;
	int			satisfied;
	long		l_teat;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread;
	t_sapien	*s;
}	t_philo;

typedef struct s_sapien
{
	long	n_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	n_eats;
	long		end_d;
	long		e_arrive;
	long	s_simulation;
	t_philo	*philos;
	t_fork	*forks;
	t_mut	w_mut;
	t_mut	write;
}	t_sapien;

long	ft_atol(const char *str);
int		check_num_argv(int ac);
int		ft_strlen(char *str);
int		check_args(int ac, char **av);
int		error(char *s);
int		init_dining(t_sapien *s, char **av);
int		handle_thread(pthread_t *thread, void *(*ft)(void *),
			void *s, char op);
int		handle_mutex(t_mut *mutex, char op);
void	set(t_mut *mut, long *dst, long value);
long	get(t_mut *mut, long *src);
long	get_time(char measure);
int		start(t_sapien *s);
void	write_status(t_status s, t_philo *p);
#endif
