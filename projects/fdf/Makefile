NAME = fdf
SRC = fdf.c fdf_parser.c fdf_painter.c fdf_key.c fdf_mouse.c fdf_brush.c errors.c
OBJDIR = objs
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))
MLX = minilibx_macos/
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
