/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:09:21 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/03 15:40:48 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once /* Protect the header from cycling */
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
typedef struct  s_data /* Struct to store the data */
{
    size_t  number_of_philo; /* var to store the number of philosophers */
    size_t  time_to_die; /* var to store the time to die for each philo */
    size_t  time_to_eat; /* var to store the time to eat for each philo */
    size_t  time_to_sleep; /* var to store the time to sleep for each philo */
    size_t  num_of_t_to_eat; /* var to store the number of time to eat for each philo */
    size_t  tmp_number; /*That's a temporary number to work with*/
}               t_data;
typedef struct s_philo /* Struct to store the data about each philo */
{
    size_t		    number_of_philo; /* var to store the number of philosophers */
    size_t		    time_to_die; /* var to store the time to die for each philo */
    size_t		    time_to_eat; /* var to store the time to eat for each philo */
    size_t		    time_to_sleep; /* var to store the time to sleep for each philo */
    size_t		    num_of_t_to_eat; /* var to store the number of time to eat for each philo */
	pthread_t	    philo_id; /* var to store the philo id */
    int64_t         philo_index; /* var to store the philo index */
    pthread_mutex_t *forks; /* var to store an array of forks */
    size_t          start; /* vat to store the creation time for each philo and the time he start eating*/
    pthread_mutex_t print;
}				t_philo;

size_t	ft_strlen(char  *string);
size_t	ft_atoi(char    *string);
uint8_t	is_number(char  *number);
uint8_t	create_threads(t_philo  *philos, t_data *data, pthread_mutex_t *forks);
pthread_mutex_t	*create_mutex(int64_t number_of_philo);
void	error(char *string);
void    free_data(t_data *data);
uint8_t    free_forks(pthread_mutex_t *forks, size_t philo_number);
void    free_philo(t_philo *philos);
void    *tasks(void *arg);
void	odd_philo_imp(t_philo *philos);
void 	even_philo_imp(t_philo *philos);
void    eat(t_philo *philos);
void    ft_sleep(t_philo *philos);
void    think(t_philo *philos);
uint8_t main_helper(t_philo *philos, t_data *data, pthread_mutex_t *forks);
int64_t modulos(int64_t index, int64_t mod);
size_t get_time(void);
void	think(t_philo *philos);
#define TO_USECOND 1e3
#define TO_MSECOND 1e3