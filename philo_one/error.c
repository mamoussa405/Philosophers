/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:06:26 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/07 20:46:01 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    error(char *string)
{
    write(2, string, ft_strlen(string));
}

void    free_data(t_data *data)
{
    free(data);
    data = NULL;
}

void    free_philo(t_philo *philos)
{
    free(philos);
    philos = NULL;
}

uint8_t    free_forks(pthread_mutex_t *forks, size_t philo_number)
{
    size_t  i;

    i = 0;
    while (--philo_number >= 0)
    {
        if (pthread_mutex_destroy(&forks[i]))
        {
            error("Failed to destroy mutex: ");
            write(2, &i, 1);
            write(2, "\n", 1);
            return (1);
        }
        i++;
    }
    free(forks);
    forks = NULL;
    return (0);
}