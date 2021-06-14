/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:31:54 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/12 16:28:51 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void print(t_philo *philos, char *string, int64_t index, uint8_t is_died)
{
    sem_wait(philos->print);
    ft_putnbr_fd(get_time() - g_time, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(index, 1);
    ft_putstr_fd(string, 1);
    ft_putstr_fd("\033[0m", 1);
    if (!is_died)
        sem_post(philos->print);
}

void print_forks(t_philo *philos, char *string, int64_t index, int64_t fork_index)
{
    sem_wait(philos->print);
    ft_putnbr_fd(get_time(), 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(index, 1);
    ft_putstr_fd(string, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(fork_index, 1);
    ft_putstr_fd("\n", 1);
    sem_post(philos->print);
}