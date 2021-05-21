/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:09:51 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/21 12:20:27 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	store_data(t_data *data, char *string, uint16_t index)
{
	if (index == 1)
		data->number_of_philo = ft_atoi(string);
	else if (index == 2)
		data->time_to_die = ft_atoi(string);
	else if (index == 3)
		data->time_to_eat = ft_atoi(string);
	else if (index == 4)
		data->time_to_sleep = ft_atoi(string);
	else if (index == 5)
		data->num_of_t_to_eat = ft_atoi(string);
}

uint8_t	check_args_helper(t_data *data,char *string,  size_t length)
{
	data->tmp_number = ft_atoi(string + 1);
	if (data->tmp_number > 8446744073709551615 || (int)(string[0] - '0') > 1)
	{
		write(2, "Invalid number: ", ft_strlen("Invalid number: "));
		write(2, string, length);
		return (1);
	}
	return (0);
}

uint8_t	check_args(int argc, char **argv, t_data *data)
{
	uint16_t	i;
	size_t		length;

	i = 1;
	while (i < argc)
	{
		length = ft_strlen(argv[i]); /* Calculate the length of each arg */
		/* Check if there's an overflow or it's not a number */
		if (length > 20 || !is_number(argv[i]))
		{
			write(2, "Invalid number: ", ft_strlen("Invalid number: "));
			write(2, argv[i], length);
			return (1);
		}
		if (length == 20)
			if (check_args_helper(data, argv[i], length))
				return (1);
		/*-----------------------------------------------------*/
		store_data(data, argv[i], i);
		i++;
	}
	return (0);
}

t_data	*read_data(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6) /* Check for the number of arguments */
	{
		write(2, "Wrong number of arguments\n",
		ft_strlen("Wrong number of arguments\n"));
		return (NULL);
	}
	data = (t_data*)malloc(sizeof(t_data)); /* Allocate the struct to store data */
	if (!data) /* In case malloc failed to allocate the given memroy */
	{
		write(2, "Malloc failled\n",
		ft_strlen("Malloc failled\n"));
		return (NULL);
	}
	if (check_args(argc, argv, data)) /* Now let's check if the arguments are valid */
		return (NULL);
	return (data);
}

int	main(int argc, char **argv)
{
    t_data	*data;

	data = read_data(argc, argv); /* read and parse data */
	if (!data)
		return (1);
	return (0);
}