/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:36:28 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/01 17:41:59 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t  ft_strlen(char *string)
{
    size_t i;

    i = 0;
    while (string[i])
        i++;
    return (i);
}

size_t  ft_atoi(char *string)
{
    size_t res;
    size_t i;

    i = 0;
    res = 0;
    while (string[i])
    {
        res = (res * 10) + string[i] + '0';
        i++;
    }
    return (res);
}