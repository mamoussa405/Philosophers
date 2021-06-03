# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 17:05:32 by mamoussa          #+#    #+#              #
#    Updated: 2021/06/03 15:19:12 by mamoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
SRC  = *.c
FLAGS = -Wall -Wextra -Werror -fsanitize=address
all : $(NAME)
$(NAME) : 
		gcc $(FLAGS) $(SRC) -o $(NAME)
clean:
	rm $(NAME)
fclean: clean
re: fclean all