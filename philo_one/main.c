/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:09:51 by mamoussa          #+#    #+#             */
/*   Updated: 2021/05/01 17:31:00 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint8_t	check_args(int argc, char **argv)
{
	uint16_t	i;
	uint16_t	j;
	size_t		length;


	i = 1;
	j = 0;
	while (i < argc)
	{
		length = ft_strlen(argv[i]);
		if (length > 20)
		{
			printf("Invalid number: %s\n", argv[i]);
			return (1);
		}
		j = 0;
		while (j < length)
		{
			/* code */
		}
	}
}

t_data	*read_data(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (NULL);
	}
	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
	{
		printf("Malloc failled\n");
	return (NULL);
	}
	if (check_args(argc, argv))
		return (NULL);
	return (data);
}

int	main(int argc, char **argv)
{
    t_data	*data;

	data = read_data(argc, argv);
	return (0);
}