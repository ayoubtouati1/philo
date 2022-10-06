# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouati <atouati@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 02:30:46 by atouati           #+#    #+#              #
#    Updated: 2022/10/05 15:34:54 by atouati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  philosophers.c ft_atoi.c philo_utils_2.c philo_utils.c main.c philo_utils_3.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -fsanitize=thread -g

clean : 

fclean :
	rm -f $(NAME)

re : fclean all
