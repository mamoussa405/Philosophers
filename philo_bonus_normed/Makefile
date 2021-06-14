# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 17:05:32 by mamoussa          #+#    #+#              #
#    Updated: 2021/06/14 15:59:50 by mamoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRC  = controle_threads.c create_philosophers.c error.c ft_print.c main_helper.c \
	main.c take_forks.c tasks.c to_streames.c tools.c
FLAGS = -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : 
		gcc $(FLAGS) $(SRC) -o $(NAME)
clean:
	rm $(NAME)
fclean: clean
re: fclean all