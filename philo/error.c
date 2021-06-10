/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:06:26 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/10 13:30:34 by mamoussa         ###   ########.fr       */
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

void    free_forks(pthread_mutex_t *forks)
{
    free(forks);
    forks = NULL;
}