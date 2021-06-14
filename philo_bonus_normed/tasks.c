/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:16:27 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 15:52:00 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eat(t_philo *philos)
{
	size_t	start;

	sem_wait(philos->is_eating);
	philos->start = get_time();
	philos->eating_count++;
	print(philos, " \033[0;34mis eating\n", philos->philo_index, 0);
	start = get_time();
	usleep(philos->ptr->time_to_eat * TO_USECOND - 20000);
	while (get_time() - start < philos->ptr->time_to_eat)
	{
	}
	sem_post(philos->is_eating);
}

void	ft_sleep(t_philo *philos)
{
	size_t	start;

	print(philos, " is sleeping\n", philos->philo_index, 0);
	start = get_time();
	usleep(philos->ptr->time_to_sleep * TO_USECOND - 20000);
	while (get_time() - start < philos->ptr->time_to_sleep)
	{
	}
}

void	think(t_philo *philos)
{
	print(philos, " \033[0;33mis thinking\n", philos->philo_index, 0);
}

void	tasks(t_philo *philos)
{
	while (1)
	{
		take_forks(philos);
		ft_sleep(philos);
		think(philos);
	}
}
