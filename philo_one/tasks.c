/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:16:27 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/03 13:13:24 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eat(t_philo *philos)
{
	philos->start = get_time();
	pthread_mutex_lock(&philos->print);
	printf("%zu %lld is eating\n", get_time(), philos->philo_index);
	usleep(philos->time_to_eat * TO_USECOND);
	pthread_mutex_unlock(&philos->print);
}

void	ft_sleep(t_philo *philos)
{
	pthread_mutex_lock(&philos->print);
	printf("%zu %lld is sleeping\n", get_time(), philos->philo_index);
	usleep(philos->time_to_sleep * TO_USECOND);
	pthread_mutex_unlock(&philos->print);
}

void	think(t_philo *philos)
{
	pthread_mutex_lock(&philos->print);
	printf("%zu %lld is thinking\n", get_time(), philos->philo_index);
	pthread_mutex_unlock(&philos->print);
}

void    *tasks(void *arg)
{
    t_philo *philos;

	philos = (t_philo*)arg;
	while (1)
	{
		/* implementation for odd philo indexs */
		if (philos->philo_index % 2)
			odd_philo_imp(philos);
		/***************************************/
		/* implementation for even philo indexs */
		else
			even_philo_imp(philos);
		/****************************************/
    }
    return (NULL);
}