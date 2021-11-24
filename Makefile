# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 09:09:02 by ynakamot          #+#    #+#              #
#    Updated: 2021/11/24 19:59:55 by ynakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRCFILE =	src/ft_printf.c \
			src/check_format.c \
			src/output_subfunc.c \
			src/output_int.c \
			src/output_str.c \
			src/output_hex.c


OBJECTS = $(SRCFILE:.c=.o)

all: $(NAME)

$(LIBFT):
	git submodule init && git submodule update
	$(MAKE) -C ./libft

$(NAME): $(LIBFT) $(OBJECTS)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I. -I./libft

test: $(NAME)
	gcc -g main.c -I. -I./libft -L. -lftprintf -o test.out

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft