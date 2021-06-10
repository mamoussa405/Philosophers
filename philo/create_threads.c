/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:02:19 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/08 12:32:16 mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint8_t create_odds(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
    size_t  i;
    size_t  philo_number_tmp;

    philo_number_tmp = data->number_of_philo; /* take a copy of number of philosophers */
    i = 0;
    while (i < philo_number_tmp)
    {
        philos[i].philo_index = i + 1; /* store the index of each philo */
        philos[i].forks = forks; /*  store the array of forks for each philo */
        philos[i].start = get_time(); /* store the creation time for each philo */
        philos[i].ptr = data; /* var to store the shared data */
        philos[i].is_eating = 0; /* flag to controle the eating of a philo */
        philos[i].eating_count = 0; /* A counter to controle how many time each philo must eat */
        pthread_mutex_init(&philos[i].eating, NULL); /* initialize a mutex to control the eating */
        if (pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]))
        {
            error("Failed to create the thread: ");
            write(2, &i, 1);
            write(2, "\n", 1);
            return (1);
        }
        i += 2;
    }
    return (0);
}

uint8_t create_evens(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
    size_t  i;
    size_t  philo_number_tmp;

    philo_number_tmp = data->number_of_philo; /* take a copy of number of philosophers */
    i = 1;
    while (i < philo_number_tmp)
    {
        philos[i].philo_index = i + 1; /* store the index of each philo */
        philos[i].forks = forks; /*  store the array of forks for each philo */
        philos[i].start = get_time(); /* store the creation time for each philo */
        philos[i].ptr = data; /* var to store the shared data */
        philos[i].is_eating = 0; /* flag to controle the eating of a philo */
        philos[i].eating_count = 0; /* A counter to controle how many time each philo must eat */
        pthread_mutex_init(&philos[i].eating, NULL); /* initialize a mutex to control the eating */
        if (pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]))
        {
            error("Failed to create the thread: ");
            write(2, &i, 1);
            write(2, "\n", 1);
            return (1);
        }
        i += 2;
    }
    return (0);
}

uint8_t create_threads(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
    pthread_mutex_init(&data->print, NULL);
    /* Create odd indexed philosophers */
    if (create_odds(philos, data, forks))
        return (1);
    /**********************************/
    usleep(1e3);
    /* Create even idexed philosophers */
    if (create_evens(philos, data, forks))
        return (1);
    /**********************************/
    /* controle the death of each philo */
    controle_the_threads(philos, data);
    /******************************************/
    return (0);
}