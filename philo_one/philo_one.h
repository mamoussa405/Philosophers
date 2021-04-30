/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:09:21 by mamoussa          #+#    #+#             */
/*   Updated: 2021/04/30 16:54:57 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
typedef struct  s_data
{
    size_t  number_of_philo;
    size_t  time_to_die;
    size_t  time_to_eat;
    size_t  time_to_sleep;
    size_t  num_of_t_to_eat;
}               t_data;