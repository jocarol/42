# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrau <agrau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 10:50:45 by agrau             #+#    #+#              #
#    Updated: 2017/01/23 12:28:17 by agrau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAME_SO = libft.so

OPTIONS = -Wall -Werror -Wextra

CC = clang

SRCS = 	ft_atoi.c\
		ft_bzero.c\
		ft_memccpy.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_strcat.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_intlen.c\
		ft_intlen_base.c\
		ft_putnbr.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_isascii.c\
		ft_abs.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_isspace.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_putendl.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstadd_tail.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_sqrt.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
	@$(CC) $(OPTIONS) -c $(SRCS) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft : \033[33;32mCompilation succeeded.\033[0m"

so:
	$(CC) -c -fPIC $(OPTIONS) $(SRCS) 
	$(CC) -shared -o libft.so $(OBJDIR)/$(OBJS)

clean:
	@echo "libft : \033[33;31mDeleting objects...\033[0m"
	@rm -rf $(OBJS)
	@echo "libft : \033[33;31mDeleting done.\033[0m"

fclean: clean
	@echo "libft : \033[33;31mDeleting binaries...\033[0m"
	@rm -f $(NAME)
	@rm -f $(NAME_SO)
	@echo "libft : \033[33;31mDeleting done.\033[0m"

re: fclean all

.PHONY: all clean fclean re
