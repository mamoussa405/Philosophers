/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_philo_imp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:39:26 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/03 12:05:42 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void 	even_philo_imp(t_philo *philos)
{
    /* take the right fork */
    pthread_mutex_lock(&philos->forks[modulos(philos->philo_index - 1,
    philos->number_of_philo)]);
    printf("%zu %lld has taken a fork %lld\n", get_time(), philos->philo_index, 
    modulos(philos->philo_index - 1, philos->number_of_philo));
    /***********************/
    /* take the left fork */
    pthread_mutex_lock(&philos->forks[modulos(philos->philo_index,
    philos->number_of_philo)]);
    printf("%zu %lld has taken a fork %lld\n", get_time(), philos->philo_index,
    modulos(philos->philo_index, philos->number_of_philo));
    /*********************/
    // pthread_mutex_unlock(&philos->forks[philos->number_of_philo]);
    eat(philos);
    /* release the left fork */
    pthread_mutex_unlock(&philos->forks[modulos(philos->philo_index,
    philos->number_of_philo)]);
    /*************************/
    /* release the right fork */
    pthread_mutex_unlock(&philos->forks[modulos(philos->philo_index - 1,
    philos->number_of_philo)]);
    /**************************/
    ft_sleep(philos);
    think(philos);
}