# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avogt <avogt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 16:23:39 by ralleman          #+#    #+#              #
#    Updated: 2020/06/19 16:43:39 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
define SRC_NAME
ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_itoa_u.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c\
ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_strndup.c\
get_next_line.c ft_convert_base.c ft_putnbr_u.c ft_strup.c ft_strlow.c\
ft_isspace.c ft_putnbr_l.c ft_putnbr_prec.c ft_putstr_prec.c
endef
FLAGS = -Wall -Werror -Wextra
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)

all: $(NAME)

$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re
