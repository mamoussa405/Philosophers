/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:10:50 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 14:57:09 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint8_t	controle_the_death(t_philo *philos)
{
	size_t	current_time;

	sem_wait(philos->is_eating);
	current_time = get_time();
	if (philos->ptr->num_of_t_to_eat != -1
		&& philos->eating_count >= philos->ptr->num_of_t_to_eat)
	{
		sem_wait(philos->print);
		if (philos->forks_count > 0)
			while (philos->forks_count--)
				sem_post(philos->sem);
		exit(0);
	}
	if (current_time - philos->start > philos->ptr->time_to_die)
	{
		print(philos, " \033[0;31mdied\n", philos->philo_index, 1);
		return (1);
	}
	sem_post(philos->is_eating);
	return (0);
}

void	*thread_controle(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (controle_the_death(philos))
			exit(1);
		usleep(1e3);
	}
	return (NULL);
}
