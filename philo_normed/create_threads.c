/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:02:19 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 16:22:17 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint8_t	create_odds(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	size_t	i;
	size_t	philo_number_tmp;

	philo_number_tmp = data->number_of_philo;
	i = 0;
	while (i < philo_number_tmp)
	{
		philos[i].philo_index = i + 1;
		philos[i].forks = forks;
		philos[i].start = get_time();
		philos[i].ptr = data;
		philos[i].is_eating = 0;
		philos[i].eating_count = 0;
		pthread_mutex_init(&philos[i].eating, NULL);
		if (pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]))
		{
			error("Failed to create the thread: ");
			write(2, &i, 1);
			write(2, "\n", 1);
			return (1);
		}
		i += 2;
	}
	return (0);
}

uint8_t	create_evens(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	size_t	i;
	size_t	philo_number_tmp;

	philo_number_tmp = data->number_of_philo;
	i = 1;
	while (i < philo_number_tmp)
	{
		philos[i].philo_index = i + 1;
		philos[i].forks = forks;
		philos[i].start = get_time();
		philos[i].ptr = data;
		philos[i].is_eating = 0;
		philos[i].eating_count = 0;
		pthread_mutex_init(&philos[i].eating, NULL);
		if (pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]))
		{
			error("Failed to create the thread: ");
			write(2, &i, 1);
			write(2, "\n", 1);
			return (1);
		}
		i += 2;
	}
	return (0);
}

uint8_t	create_threads(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	pthread_mutex_init(&data->print, NULL);
	if (create_odds(philos, data, forks))
		return (1);
	usleep(1e3);
	if (create_evens(philos, data, forks))
		return (1);
	controle_the_threads(philos, data);
	return (0);
}
