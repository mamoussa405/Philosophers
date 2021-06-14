/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:38:13 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 15:49:05 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks(t_philo *philos)
{
	sem_wait(philos->sem);
	philos->forks_count++;
	print(philos, " \033[0;32mhas taken a fork\n", philos->philo_index, 0);
	sem_wait(philos->sem);
	philos->forks_count++;
	print(philos, " \033[0;32mhas taken a fork\n", philos->philo_index, 0);
	eat(philos);
	sem_post(philos->sem);
	philos->forks_count--;
	sem_post(philos->sem);
	philos->forks_count--;
}
