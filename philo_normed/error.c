/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:06:26 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 16:58:52 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	error(char *string)
{
	write(2, string, ft_strlen(string));
}

void	free_data(t_data *data)
{
	free(data);
	data = NULL;
}

void	free_philo(t_philo *philos)
{
	free(philos);
	philos = NULL;
}

void	free_forks(pthread_mutex_t *forks)
{
	free(forks);
	forks = NULL;
}

uint8_t	check_if_args_valid(t_data *data)
{
	if (!data->number_of_philo)
	{
		printf("number of philo must be greater then 0\n");
		return (1);
	}
	if (!data->time_to_die)
	{
		printf("time to die must be greater then 0\n");
		return (1);
	}
	if (!data->time_to_eat)
	{
		printf("time to eat must be greater then 0\n");
		return (1);
	}
	if (!data->time_to_sleep)
	{
		printf("time to sleep must be greater then 0\n");
		return (1);
	}
	return (0);
}
