/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:16:27 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/08 18:30:38 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eat(t_philo *philos)
{
	pthread_mutex_lock(&philos->eating);
	philos->start = get_time();
	// printf("%zu %lld is eating\n", get_time() - g_time, philos->philo_index + 1);
	print(philos, " is eating\n", philos->philo_index);
	// ft_usleep(philos->time_to_eat * TO_USECOND);
	size_t start = get_time();
	usleep(philos->time_to_eat * TO_USECOND - 20000);
	while(get_time() - start < philos->time_to_eat);
	// usleep(philos->time_to_eat * TO_USECOND);
	pthread_mutex_unlock(&philos->eating);
}

void	ft_sleep(t_philo *philos)
{
	// printf("%zu %lld is sleeping\n", get_time() - g_time, philos->philo_index + 1);
	print(philos, " is sleeping\n", philos->philo_index);
	// ft_usleep(philos->time_to_sleep * TO_USECOND);
	size_t start = get_time();
	usleep(philos->time_to_sleep * TO_USECOND - 20000);
	while(get_time() - start < philos->time_to_sleep);
}

void	think(t_philo *philos)
{
	print(philos, " is thinking\n", philos->philo_index);
	// printf("%zu %lld is thinking\n", get_time() - g_time, philos->philo_index + 1);
}

void    *tasks(void *arg)
{
    t_philo *philos;

	philos = (t_philo*)arg;
	while (1)
	{
		/* this part each philo should take two forks or waiting for them to be avaiable */
		take_forks_odd(philos);
		/***************************************/
    }
    return (NULL);
}