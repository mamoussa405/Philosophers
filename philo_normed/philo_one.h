/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:09:21 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 16:59:07 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
typedef struct s_data
{
	size_t			number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int64_t			num_of_t_to_eat;
	size_t			tmp_number;
	size_t			sum;
	pthread_mutex_t	print;
}				t_data;

typedef struct s_philo
{
	pthread_t		philo_id;
	int64_t			philo_index;
	pthread_mutex_t	*forks;
	size_t			start;
	t_data			*ptr;
	pthread_mutex_t	eating;
	uint8_t			is_eating;
	int64_t			eating_count;
}				t_philo;

size_t			ft_strlen(char *string);
size_t			ft_atoi(char *string);
uint8_t			is_number(char *number);
uint8_t			create_threads(t_philo *philos, t_data *data,
					pthread_mutex_t *forks);
pthread_mutex_t	*create_mutex(int64_t number_of_philo);
void			error(char *string);
void			free_data(t_data *data);
void			free_forks(pthread_mutex_t *forks);
void			free_philo(t_philo *philos);
void			*tasks(void *arg);
void			take_forks_odd(t_philo *philos);
void			take_forks_even(t_philo *philos);
void			eat(t_philo *philos);
void			ft_sleep(t_philo *philos);
void			think(t_philo *philos);
uint8_t			main_helper(t_philo *philos, t_data *data,
					pthread_mutex_t *forks);
size_t			get_time(void);
void			think(t_philo *philos);
void			ft_putnbr_fd(int64_t n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			print(t_philo *philos, char *string, int64_t index);
void			print_forks(t_philo *philos, char *string, int64_t index,
					int64_t fork_index);
void			controle_the_threads(t_philo *philos, t_data *data);
uint8_t			check_if_args_valid(t_data *data);
# define TO_USECOND 1e3
# define TO_MSECOND 1e3
#endif
