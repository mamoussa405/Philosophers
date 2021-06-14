/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:38:13 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 16:42:03 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks_odd(t_philo *philos)
{
	pthread_mutex_lock(&philos->forks[philos->philo_index
		% philos->ptr->number_of_philo]);
	print(philos, " \033[0;32mhas taken a fork\n", philos->philo_index);
	pthread_mutex_lock(&philos->forks[philos->philo_index - 1]);
	print(philos, " \033[0;32mhas taken a fork\n", philos->philo_index);
	eat(philos);
	pthread_mutex_unlock(&philos->forks[philos->philo_index - 1]);
	pthread_mutex_unlock(&philos->forks[philos->philo_index
		% philos->ptr->number_of_philo]);
}
