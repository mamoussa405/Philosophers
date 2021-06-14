/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:10:50 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 16:13:30 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint8_t	number_of_time_to_eat(t_data *data)
{
	if (data->num_of_t_to_eat != -1 && data->sum
		>= (data->num_of_t_to_eat * data->number_of_philo))
	{
		pthread_mutex_lock(&data->print);
		printf("\033[0;31mAll philosophers ate at least %lld times\n",
			data->num_of_t_to_eat);
		return (1);
	}
	return (0);
}

uint8_t	controle_the_death(t_philo *philos, t_data *data)
{
	register size_t	i;
	size_t			current_time;

	i = 0;
	while (i < data->number_of_philo)
	{
		current_time = get_time();
		if (!philos[i].is_eating)
		{
			pthread_mutex_lock(&philos[i].eating);
			if (current_time - philos[i].start > philos[i].ptr->time_to_die)
			{
				print(philos, " \033[0;31mdied\n", philos[i].philo_index);
				pthread_mutex_lock(&philos[i].ptr->print);
				return (1);
			}
			pthread_mutex_unlock(&philos[i].eating);
			data->sum += philos[i].eating_count;
		}
		usleep(1e3);
		i++;
	}
	return (0);
}

void	controle_the_threads(t_philo *philos, t_data *data)
{
	while (1)
	{
		data->sum = 0;
		if (controle_the_death(philos, data))
			return ;
		if (number_of_time_to_eat(data))
			return ;
	}
}
