# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 09:09:02 by ynakamot          #+#    #+#              #
#    Updated: 2020/11/15 10:58:26 by ynakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCFILE =	src/ft_printf.c \
			src/check_format.c \
			src/output_subfunc.c \
			src/output_int.c \
			src/output_str.c \
			src/output_hex.c



OBJECTS = $(SRCFILE:.c=.o)

all: $(NAME)

libft:
	$(MAKE) bonus -C ./libft

$(NAME): libft $(OBJECTS)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I. -I./libft

test: libft
	gcc -g main.c $(SRCFILE) -I. -I./libft -L./libft -lft -o test.out

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft