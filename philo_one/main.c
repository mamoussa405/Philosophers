/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:09:51 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/01 16:38:49 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data	*read_data(void)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	return (data);
}

int	main(int argc, char **argv)
{
    t_data	*data;

	data = read_data();
	return (0);
}