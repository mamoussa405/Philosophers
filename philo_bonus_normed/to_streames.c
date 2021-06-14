/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_streames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:16:42 by mamoussa          #+#    #+#             */
/*   Updated: 2021/06/14 15:55:21 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static	void	ft_print(char n, int fd)
{
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int64_t n, int fd)
{
	unsigned int	div;

	div = n;
	if (n < 0)
	{
		ft_print('-', fd);
		div = div * -1;
	}
	if (div > 9)
	{
		ft_putnbr_fd(div / 10, fd);
		ft_print((div % 10) + '0', fd);
	}
	if (div <= 9)
		ft_print(div + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_print(*s, fd);
			s++;
		}
	}
}
