CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c philo_utils.c philo_utils2.c philo_init.c philo_simulate.c philo_get_forks.c philo_get_a_meal.c philo_get_a_sleep.c philo_exit.c
OBJS = $(SRCS:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c philosophers.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
