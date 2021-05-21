/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:09:21 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/21 12:09:40 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once /* Protect the header from cycling */
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
typedef struct  s_data /* Structer to store the data */
{
    size_t  number_of_philo; /* var to store the number of philosophers */
    size_t  time_to_die; /* var to store the time to die for each philo */
    size_t  time_to_eat; /* var to store the time to eat for each philo */
    size_t  time_to_sleep; /* var to store the time to sleep for each philo */
    size_t  num_of_t_to_eat; /* var to store the number of time to eat for each philo */
    size_t  tmp_number; /*That's a temporary number to work with*/
}               t_data;

size_t  ft_strlen(char  *string);
size_t  ft_atoi(char    *string);
uint8_t is_number(char  *number);