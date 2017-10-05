# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 18:59:53 by jocarol           #+#    #+#              #
#    Updated: 2017/06/21 16:16:44 by jocarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

#HEADER = libft.h
#INC=includes/

#SRCS_PATH=srcs/

SRCS = ft_atoi.c ft_atoi_base.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
  ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c \
	ft_isupper.c ft_iswhitespace.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_reverse.c \
	ft_strcat.c ft_strchr.c ft_strchri.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	ft_strlen.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnjoin.c \
	ft_strnstr.c ft_strrchr.c	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_swap.c ft_tolower.c ft_toupper.c get_next_line.c \


#SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ = $(addsuffix .o, $(basename $(SRCS)))

# * * P.I.M.P * *

RED=\033[0;31m
GREEN=\033[32m
ORANGE=\033[0;33m
NC=\033[0m

# * * Compilation * *

all: $(NAME)

$(NAME):
					@gcc -c $(CFLAGS) $(SRCS)
					@ar rc $(NAME) $(OBJ)
					@ranlib $(NAME)

clean:
					@$(RM) $(OBJ)

fclean: 	clean
					@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
