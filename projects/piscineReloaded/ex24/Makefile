# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 18:59:53 by jocarol           #+#    #+#              #
#    Updated: 2016/12/19 17:50:21 by jocarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

INC=includes/

SRCS_PATH=srcs/

SRCS_NAME=ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c \

SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ=ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o \

# * * Compilation * *

all: $(NAME)

$(NAME):
	@ $(CC) $(CLFAGS) -c $(SRCS) -I$(INC);
	@ar rc $(NAME) $(OBJ);
	@ranlib $(NAME);

clean:
	@ ${RM} ${OBJ}

fclean: clean
	@ ${RM} ${NAME}

re : fclean all
