# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 18:18:17 by jocarol           #+#    #+#              #
#    Updated: 2017/01/05 20:06:29 by jocarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_display_file

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=ft_display_file.c

all : $(NAME)

$(NAME) :
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) -o $(NAME) ft_display_file.o

clean :
	$(RM) ft_display_file.o

fclean : clean
	$(RM) $(NAME)

re : fclean all
