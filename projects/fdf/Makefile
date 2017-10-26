# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 04:51:04 by jocarol           #+#    #+#              #
#    Updated: 2017/10/26 04:59:26 by jocarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = fdf.c check_map.c display.c keys.c mouse.c put_line.c errors.c
OBJDIR = objs
CFLAGS = -g -Wall -Wextra -Werror
CC = gcc
OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))
MLX = minilibx_macos
FRAMEWORKS = -framework OpenGL -framework AppKit

all:${NAME}

${NAME}: ${OBJ}
	@make -C libft/
	@make -C ${MLX}
	@echo Compiling ${NAME}
	@${CC} ${CFLAGS} -g -Ilibft/includes/ -I. -I${MLX} -Llibft/ -lft \
		-L${MLX} -lmlx ${FRAMEWORKS} -o $@ ${OBJ}
	@echo "\033[32mMake okay =)\033[0m"

${OBJDIR}/%.o : ./srcs/%.c
	@echo Compiling $@
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -g -Ilibft/includes/ -I. -I${MLX} -c -o $@ $<

clean:
	@echo clean mlx...
	@make -C ${MLX} clean
	@echo clean libft...
	@make -C libft/ clean
	@echo clean objs...
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo fclean libft...
	@make -C libft/ fclean
	@echo clean ${NAME}...
	@/bin/rm -f ${NAME}

re: fclean all

build: ${OBJ}

.PHONY: all clean fclean re test
