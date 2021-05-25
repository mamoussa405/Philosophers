/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:56:34 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/24 14:32:11 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

pthread_mutex_t    *create_mutex(size_t mutex_number)
{
    pthread_mutex_t *mutex_id;

    mutex_id = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * mutex_number);
    while (mutex_number--)
        pthread_mutex_init(&mutex_id[mutex_number], NULL);
    return (mutex_id);
}