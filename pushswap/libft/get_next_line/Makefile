# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:52:01 by jonghopa          #+#    #+#              #
#    Updated: 2023/07/10 17:50:17 by jonghopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
SRCS_M = \
get_next_line_utils.c \
get_next_line.c

OBJS_MAN = $(SRCS_M:.c=.o)

OBJS = $(OBJS_MAN)

all:
	make $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

*.o: *.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS_MAN)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
