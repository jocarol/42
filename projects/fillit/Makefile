# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrau <agrau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 15:05:47 by agrau             #+#    #+#              #
#    Updated: 2017/02/12 20:52:20 by agrau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OPTIONS = -Wall -Werror -Wextra


CC = clang

SRCS = main.c\
	   alloc_fillit.c\
	   free_fillit.c\
	   parsing_fillit.c\
	   backtracking_fillit.c\
	   error_fillit.c\
	   print_fillit.c


all: $(NAME)
	@echo "fillit : \033[33;32mCompilation succeeded.\033[0m"

$(NAME): libft
	@$(CC) $(OPTIONS) $(SRCS) libft/libft.a -o $(NAME)

libft:
	@make all -C libft/

clean:
	@make clean -C libft/

fclean:
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "fillit : \033[33;31mDeleting done.\033[0m"

re: fclean all

.PHONY: all clean fclean libft re
