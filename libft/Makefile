# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:52:01 by jonghopa          #+#    #+#              #
#    Updated: 2023/10/04 17:10:18 by jonghopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS_L = \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c

SRCS_A = \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c

SRCS_B = \
ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

OBJS_MAN = $(SRCS_L:.c=.o) $(SRCS_A:.c=.o)
OBJS_BONUS = $(SRCS_B:.c=.o)

ifdef BONUS
OBJS = $(OBJS_BONUS) $(OBJS_MAN)
else
OBJS = $(OBJS_MAN)
endif

all:
	make $(NAME)
	sleep 1

$(NAME): $(OBJS)
	ar -rcs $@ $^

bonus:
	make BONUS=1

*.o: *.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS_MAN) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
