/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:31:54 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 15:18:54 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print(t_philo *philos, char *string, int64_t index, uint8_t is_died)
{
	sem_wait(philos->print);
	ft_putnbr_fd(get_time(), 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(index, 1);
	ft_putstr_fd(string, 1);
	ft_putstr_fd("\033[0m", 1);
	if (!is_died)
		sem_post(philos->print);
}
