/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:02:19 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 15:11:27 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_kill(t_data	*data)
{
	size_t	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		kill(data->arr[i], SIGKILL);
		i++;
	}
	free(data->arr);
	data->arr = NULL;
}

void	ft_wait(t_data *data, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		waitpid(-1, &data->status, 0);
		data->status = WEXITSTATUS(data->status);
		if (data->status)
			return ;
		else
			sem_post(philos->print);
		i++;
	}
	printf("\033[0;31mAll philosophers ate at least %lld times\n",
		data->num_of_t_to_eat);
}

void	free_and_exit(t_data *data, t_philo *philos, char const *str_error)
{
	error(str_error);
	if (data->arr)
		ft_kill(data);
	free_data(data);
	free_philo(philos);
	exit(1);
}

void	philo_init(t_philo *philos, t_data *data, size_t i)
{
	sem_unlink("/philo_bonus_eating");
	philos->is_eating = sem_open("/philo_bonus_eating", O_CREAT | O_EXCL,
			S_IRUSR | S_IWUSR, 1);
	philos->philo_index = i;
	philos->ptr = data;
	philos->forks_count = 0;
	philos->start = get_time();
	pthread_create(&philos->th_id, NULL, thread_controle, philos);
	tasks(philos);
}

void	create_philos(t_philo *philos, t_data *data)
{
	size_t	i;

	i = 1;
	data->tmp_number = data->number_of_philo;
	data->arr = (pid_t *)malloc(sizeof(pid_t) * data->number_of_philo);
	if (!data->arr)
		free_and_exit(data, philos, "Malloc failed\n");
	while (data->tmp_number--)
	{
		philos->philo_id = fork();
		if (philos->philo_id < 0)
			free_and_exit(data, philos, "Fork failed\n");
		if (philos->philo_id == 0)
			philo_init(philos, data, i);
		else
			data->arr[i - 1] = philos->philo_id;
		i++;
	}
	ft_wait(data, philos);
	ft_kill(data);
}
