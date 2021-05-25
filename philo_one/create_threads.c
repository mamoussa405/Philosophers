/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:02:19 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/25 15:15:32 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    *tasks(void *arg)
{
    t_philo *philos;

    philos = (t_philo*)arg;
    while (1)
        printf("philo %zu is thinking\n", philos->philo_index);
    return (NULL);
}

void   copy_data(t_philo *philo, t_data *data) 
{
    philo->number_of_philo = data->number_of_philo;
    philo->time_to_die = data->time_to_die;
    philo->time_to_eat = data->time_to_eat;
    philo->time_to_sleep = data->time_to_sleep;
    philo->num_of_t_to_eat = data->num_of_t_to_eat;
}

void    create_threads(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
    size_t  i;
    size_t  philo_number_tmp;

    philo_number_tmp = data->number_of_philo; /* take a copy of number of philosophers */
    i = 0;
    while (philo_number_tmp--)
    {
        philos[i].philo_index = i; /* store the index of each philo */
        philos[i].forks = forks; /*  store the array of forks for each philo */
        copy_data(&philos[i], data); /* copy the data to each philo */
        pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]);
        i++;
    }
    /* join the main thread with other threads */
    i = 0;
    while (data->number_of_philo--)
        pthread_join(philos[i++].philo_id, NULL);
    /******************************************/
}