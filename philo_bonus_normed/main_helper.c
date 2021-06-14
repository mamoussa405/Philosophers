/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:02:58 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 15:19:56 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	main_helper(t_philo *philos, t_data *data)
{
	if (!philos)
	{
		free_data(data);
		error("Malloc failled\n");
		exit(1);
	}
	create_philos(philos, data);
}
