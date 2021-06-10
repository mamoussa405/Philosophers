/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:16:27 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/09 18:34:05 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eat(t_philo *philos)
{
	size_t	start;

	pthread_mutex_lock(&philos->eating);
	philos->start = get_time();
	philos->is_eating = 1;
	philos->eating_count++;
	print(philos, " \033[0;34mis eating\n", philos->philo_index);
	start = get_time();
	usleep(philos->ptr->time_to_eat * TO_USECOND - 20000);
	while(get_time() - start < philos->ptr->time_to_eat)
	{
		
	}
	philos->is_eating = 0;
	pthread_mutex_unlock(&philos->eating);
}

void	ft_sleep(t_philo *philos)
{
	size_t start;

	print(philos, " is sleeping\n", philos->philo_index);
	start = get_time();
	usleep(philos->ptr->time_to_sleep * TO_USECOND - 20000);
	while(get_time() - start < philos->ptr->time_to_sleep)
	{

	}
}

void	think(t_philo *philos)
{
	print(philos, " \033[0;33mis thinking\n", philos->philo_index);
}

void    *tasks(void *arg)
{
    t_philo *philos;

	philos = (t_philo*)arg;
	while (1)
	{
		take_forks_odd(philos); /* Allow each philo to take forks */
        ft_sleep(philos); /* Send each philo to sleep an amount of time */
        think(philos); /* After completing the sleeping task each philo have to start thinking */
    }
    return (NULL);
}