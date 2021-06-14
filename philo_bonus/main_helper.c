/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:02:58 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/10 15:40:36 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint8_t main_helper(t_philo *philos, t_data *data)
{
	if (!philos)
	{
		free_data(data);
		error("Malloc failled\n");
		return (1);
	}
	if (create_philos(philos, data))
	{
		free_data(data);
		free_philo(philos);
		return (1);
	}
    return (0);
}