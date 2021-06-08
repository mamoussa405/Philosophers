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

void   copy_data(t_philo *philo, t_data *data) 
{
    philo->number_of_philo = data->number_of_philo;
    philo->time_to_die = data->time_to_die;
    philo->time_to_eat = data->time_to_eat;
    philo->time_to_sleep = data->time_to_sleep;
    philo->num_of_t_to_eat = data->num_of_t_to_eat;
}

void    controle_the_threads(t_philo *philos, t_data *data)
{
    register size_t     i;
    size_t              current_time;

    while (1)
    {
        i = 0;
        while (i < data->number_of_philo)
        {
            current_time = get_time();
            pthread_mutex_lock(&philos[i].eating);
            if (current_time - philos[i].start > philos[i].time_to_die)
            {
                // printf("%zu %lld died\n", get_time() - g_time, (philos[i].philo_index + 1) % philos[i].number_of_philo);
                print(philos, " died\n", philos[i].philo_index + 1);
                pthread_mutex_lock(&philos[i].ptr->death);
                return ;
            }
            pthread_mutex_unlock(&philos[i].eating);
            i++;
        }
    }
}

uint8_t create_threads(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
    size_t  i;
    size_t  philo_number_tmp;

    philo_number_tmp = data->number_of_philo; /* take a copy of number of philosophers */
    i = 0;
    pthread_mutex_init(&data->print, NULL);
    pthread_mutex_init(&data->death, NULL);
    while (i < philo_number_tmp)
    {
        philos[i].philo_index = i + 1; /* store the index of each philo */
        printf("%lld\n", philos[i].philo_index);
        philos[i].forks = forks; /*  store the array of forks for each philo */
        philos[i].start = get_time(); /* store the creation time for each philo */
        philos[i].ptr = data;
        pthread_mutex_init(&philos[i].eating, NULL);
        copy_data(&philos[i], data); /* copy the data to each philo */
        if (pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]))
        {
            error("Failed to create the thread: ");
            write(2, &i, 1);
            write(2, "\n", 1);
            return (1);
        }
        i += 2;
    }
    usleep(1e3);
    i = 1;
    while (i < philo_number_tmp)
    {
        philos[i].philo_index = i + 1; /* store the index of each philo */
        printf("%lld\n", philos[i].philo_index);
        philos[i].forks = forks; /*  store the array of forks for each philo */
        philos[i].start = get_time(); /* store the creation time for each philo */
        philos[i].ptr = data;
        pthread_mutex_init(&philos[i].eating, NULL);
        copy_data(&philos[i], data); /* copy the data to each philo */
        if (pthread_create(&philos[i].philo_id, NULL, tasks, &philos[i]))
        {
            error("Failed to create the thread: ");
            write(2, &i, 1);
            write(2, "\n", 1);
            return (1);
        }
        i += 2;
    }
    /* controle the death of each philo */
    controle_the_threads(philos, data);
    /******************************************/
    return (0);
}