# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:52:01 by jonghopa          #+#    #+#              #
#    Updated: 2023/08/28 17:56:23 by jonghopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = \
ft_isdigit.c \
ft_strlen.c \
ft_strncmp.c \
ft_atoi.c \
ft_strdup.c \
ft_split.c \

OBJS = $(SRCS:.c=.o)

all:
	make $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

*.o: *.c
	$(CC) $(CFLAGS) $(CDEBUG) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
