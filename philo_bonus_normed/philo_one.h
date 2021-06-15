/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:09:21 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/15 14:01:31 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>
typedef struct s_data
{
	size_t			number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int64_t			num_of_t_to_eat;
	size_t			tmp_number;
	int				status;
	pid_t			*arr;
}				t_data;

typedef struct s_philo
{
	pid_t			philo_id;
	int64_t			philo_index;
	size_t			start;
	int64_t			eating_count;
	int64_t			forks_count;
	t_data			*ptr;
	sem_t			*sem;
	sem_t			*print;
	sem_t			*is_eating;
	pthread_t		th_id;
	size_t			sum;
}				t_philo;

size_t			ft_strlen(char const *string);
size_t			ft_atoi(char *string);
uint8_t			is_number(char *number);
void			create_philos(t_philo *philos, t_data *data);
void			error(char const *string);
void			free_data(t_data *data);
void			free_forks(pthread_mutex_t *forks);
void			free_philo(t_philo *philos);
void			tasks(t_philo *philos);
void			take_forks(t_philo *philos);
void			eat(t_philo *philos);
void			think(t_philo *philos);
void			main_helper(t_philo *philos, t_data *data);
size_t			get_time(void);
void			think(t_philo *philos);
void			ft_putnbr_fd(int64_t n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			print(t_philo *philos, char *string, int64_t index,
					uint8_t is_died);
void			print_forks(t_philo *philos, char *string, int64_t index,
					int64_t fork_index);
void			*thread_controle(void *arg);
void			check_if_args_valid(t_data *data);
# define TO_USECOND 1e3
# define TO_MSECOND 1e3
# define RM_TIME 30000
#endif
