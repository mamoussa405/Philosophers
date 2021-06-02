/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:56:34 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/28 18:42:54 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

pthread_mutex_t    *create_mutex(int64_t mutex_number)
{
    pthread_mutex_t *mutex_id;
    int             ret;

    mutex_id = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * (mutex_number + 1));
    if (!mutex_id)
    {
      write(2, "Malloc failled\n",
      ft_strlen("Malloc failled\n"));
      return (NULL);
    }
    while (mutex_number >= 0)
    {
      ret = pthread_mutex_init(&mutex_id[mutex_number], NULL);
      if (ret)
      {
        write(2, "Failed to create mutex: ",
        ft_strlen("Failed to create mutex: "));
        write(2, &mutex_number, 1);
        write(2, "\n", 1);
        return (NULL);
      }
      mutex_number--;
    }
    return (mutex_id);
}