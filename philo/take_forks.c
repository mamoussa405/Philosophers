/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:38:13 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/09 15:10:26 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks_odd(t_philo *philos)
{
        /* take the right fork */
        pthread_mutex_lock(&philos->forks[philos->philo_index
        % philos->ptr->number_of_philo]);
	print(philos, " \033[0;32mhas taken a fork\n", philos->philo_index);
        // print_forks(philos, " \033[0;32mhas taken a fork", philos->philo_index, philos->philo_index);
        /***********************/
        /* take the left fork */
        pthread_mutex_lock(&philos->forks[philos->philo_index - 1]);
	print(philos, " \033[0;32mhas taken a fork\n", philos->philo_index);
        // print_forks(philos, " \033[0;32mhas taken a fork", philos->philo_index, philos->philo_index - 1);
        /*********************/
        eat(philos);
        /* release the left fork */
        pthread_mutex_unlock(&philos->forks[philos->philo_index - 1]);
        /*************************/
        /* release the right fork */
        pthread_mutex_unlock(&philos->forks[philos->philo_index
        % philos->ptr->number_of_philo]);
        /**************************/
}