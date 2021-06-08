/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:38:13 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/08 18:21:47 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks_odd(t_philo *philos)
{
        /* take the right fork */
        pthread_mutex_lock(&philos->forks[philos->philo_index % philos->number_of_philo]);
        print_forks(philos, " has taken a fork", philos->philo_index, philos->philo_index);
        /***********************/
        /* take the left fork */
        pthread_mutex_lock(&philos->forks[philos->philo_index - 1]);
        print_forks(philos, " has taken a fork", philos->philo_index, philos->philo_index - 1);
        /*********************/
        eat(philos);
        /* release the left fork */
        pthread_mutex_unlock(&philos->forks[philos->philo_index - 1]);
        /*************************/
        /* release the right fork */
        pthread_mutex_unlock(&philos->forks[philos->philo_index % philos->number_of_philo]);
        /**************************/
        ft_sleep(philos);
        think(philos);
}