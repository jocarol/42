# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 00:03:30 by agrumbac          #+#    #+#              #
#    Updated: 2017/02/21 02:52:07 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = minilibx_macos/
RM = /bin/rm -rf
FRAMEWORKS = -framework OpenGL -framework AppKit
SRCS = draw.c errors.c keyhool.c main.c matrix.c mousehook.c parser.c print.c
#OBJS = $(addsuffix .o, $(basename $(SRCS)))
OBJ = $(SRCS:.c=.o)
INCLUDES = -I ./includes
LIB = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME):
					@make -C libft/ fclean
					@make -C libft/
					@make -C ${MLX}
					@echo Compiling ${NAME}
					gcc $(CFLAG) -I libft/ -c $(FILES)
					gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH)
					
					@echo "\033[32mfdf is ready!\033[0m"
gcc -Wall -Wextra -Werror -C /libft -C minilibx_macos/ -I includes -lft -lmlx -framework Opengl -framework Appkit
#${OBJDIR}/%.o : ./srcs/%.c
#	@echo Compiling $@
#	@/bin/mkdir -p ${OBJDIR}
#	@${CC} ${CFLAGS} -g -Ilibft/includes/ -I. -I${MLX} -c -o $@ $<

