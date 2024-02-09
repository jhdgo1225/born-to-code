# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 14:56:11 by jonghopa          #+#    #+#              #
#    Updated: 2023/09/26 18:13:54 by jonghopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = deque.a
SRCS = \
deque_create.c \
deque_create_node.c \
deque_push_front.c \
deque_push_back.c \
deque_pop_front.c \
deque_pop_back.c \
deque_front.c \
deque_back.c \
deque_size.c \
deque_empty.c \
deque_clear.c \
deque_rotate.c \
deque_reverse_rotate.c \
deque_push_swap.c \

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
