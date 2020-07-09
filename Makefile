# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avogt <avogt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 16:09:40 by avogt             #+#    #+#              #
#    Updated: 2020/07/02 15:14:57 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c parse_arg.c handle_c.c handle_s.c handle_p.c\
	handle_d.c handle_i.c handle_u.c handle_x.c redirect.c is_min.c\
	display_char.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
LIBFT = libft
DIR_S = srcs
DIR_O = tmp
HEADER = include

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o : $(DIR_S)/%.c
	@mkdir -p tmp
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $< 

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
