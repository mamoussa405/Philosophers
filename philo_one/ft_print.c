/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:31:54 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/09 15:09:26 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void print(t_philo *philos, char *string, int64_t index)
{
    pthread_mutex_lock(&philos->ptr->print);
    ft_putnbr_fd(get_time() - g_time, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(index, 1);
    ft_putstr_fd(string, 1);
    ft_putstr_fd("\033[0m", 1);
    pthread_mutex_unlock(&philos->ptr->print);
}

void print_forks(t_philo *philos, char *string, int64_t index, int64_t fork_index)
{
    pthread_mutex_lock(&philos->ptr->print);
    ft_putnbr_fd(get_time() - g_time, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(index, 1);
    ft_putstr_fd(string, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(fork_index, 1);
    ft_putstr_fd("\n", 1);
    pthread_mutex_unlock(&philos->ptr->print);
}