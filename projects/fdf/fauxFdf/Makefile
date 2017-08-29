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
SRCS = draw.c errors.c keyhook.c main.c matrix.c mousehook.c parser.c print.c
#OBJS = $(addsuffix .o, $(basename $(SRCS)))
OBJ = $(SRCS:.c=.o)
INCLUDES = -I./ -I libft/includes/
LIBS = -L libft/ -L minilibx_macos -lft
FRAMEWORKS = -framework OpenGL -framework Appkit


all : $(NAME)

$(NAME):
			
					@make -C libft/ fclean
					@make -C libft/
					@make -C ${MLX}
					@echo Compiling ${NAME}
					#$(COMPILER) $(INCLUDES) $(SRCS) $(LIBS) $(FRAMEWORKS) 					
					gcc -I ./minilibx_macos ./minilibx_macos/libmlx.a libft/libft.a $(SRCS) $(FRAMEWORKS)
					@echo "\033[32mfdf is ready!!\033[0m"

# gcc -I./ -Ilibft/includes/ *.c -L libft -L minilibx_macos -lft -lmlx -framework Opengl -framework Appkit


#${OBJDIR}/%.o : ./srcs/%.c
#	@echo Compiling $@
#	@/bin/mkdir -p ${OBJDIR}
#	@${CC} ${CFLAGS} -g -Ilibft/includes/ -I. -I${MLX} -c -o $@ $<

