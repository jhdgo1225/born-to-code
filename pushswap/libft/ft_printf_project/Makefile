# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:52:01 by jonghopa          #+#    #+#              #
#    Updated: 2023/06/29 18:01:42 by jonghopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS_M = \
ft_strlen.c \
ft_putnbr_special.c \
ft_putnbr_hex.c \
ft_conversion.c \
ft_char.c \
ft_decimal.c \
ft_unsigned.c \
ft_percent.c \
ft_string.c \
ft_hex.c \
ft_addr.c \
ft_printf.c

OBJS_MAN = $(SRCS_M:.c=.o)

OBJS = $(OBJS_MAN)

all:
	make $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

*.o: *.c
	$(CC) $(CFLAGS) $(CDEBUG) $^ -o $@

clean:
	rm -rf $(OBJS_MAN)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
