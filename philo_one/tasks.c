/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:16:27 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/02 11:35:31 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eat(t_philo *philos)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	philos->was_sleeping = 0;
	printf("%zu %lld is eating\n", (size_t)(tp.tv_sec * TO_MSECOND
	+ tp.tv_usec / TO_MSECOND), philos->philo_index);
	usleep(philos->time_to_eat * TO_USECOND);
}

void	ft_sleep(t_philo *philos)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	philos->was_sleeping = 1;
	printf("%zu %lld is sleeping\n", (size_t)(tp.tv_sec * TO_MSECOND
	+ tp.tv_usec / TO_MSECOND), philos->philo_index);
	usleep(philos->time_to_sleep * TO_USECOND);
}

void	think(t_philo *philos)
{
	struct timeval tp;
	
	gettimeofday(&tp, NULL);
	printf("%zu %lld is thinking\n", (size_t)(tp.tv_sec * TO_MSECOND
	+ tp.tv_usec / TO_MSECOND), philos->philo_index);
	if (philos->was_sleeping)
		usleep((philos->time_to_die - philos->time_to_sleep) * TO_USECOND);
	else
		usleep(philos->time_to_die * TO_USECOND);
	philos->was_sleeping = 0;
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