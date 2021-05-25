/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:02:58 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/25 19:05:44 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
uint8_t main_helper(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	if (!philos)
	{
		if (free_forks(forks, data->number_of_philo))
		{
			free_data(data);
			return (1);
		}
		free_data(data);
		error("Malloc failled\n");
		return (1);
	}
	if (create_threads(philos, data, forks))
	{
		if (free_forks(forks, data->number_of_philo))
		{
			free_philo(philos);
			free_data(data);
			return (1);
		}
		free_data(data);
		free_philo(philos);
		return (1);
	}
    return (0);
}