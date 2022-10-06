# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouati <atouati@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 02:30:46 by atouati           #+#    #+#              #
#    Updated: 2022/10/06 00:51:24 by atouati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  philosophers.c ft_atoi.c philosophers_utils_2.c philosophers_utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) #-fsanitize=thread -g

clean : 

fclean :
	rm -f $(NAME)

re : fclean all
