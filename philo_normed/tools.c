/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:36:28 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 16:48:22 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1e3) + (tp.tv_usec / 1e3));
}

void	ft_usleep(size_t time)
{
	size_t	start_time;
	size_t	cur_time;

	start_time = get_time() * 1e3;
	cur_time = 0;
	while (cur_time <= time)
	{
		cur_time = get_time() * 1e3;
		cur_time -= start_time;
	}
}

size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

uint8_t	is_number(char *number)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(number);
	i = 0;
	while (i < len)
	{
		if (!(number[i] >= '0' && number[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_atoi(char *string)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = 0;
	while (string[i])
	{
		res = (res * 10) + (string[i] - '0');
		i++;
	}
	return (res);
}
