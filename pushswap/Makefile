CC = cc
CFLAGS = -Wall -Wextra -Werror

SUBDIRS = \
./libft/libft \
./libft/ft_printf_project \
./libft/get_next_line \
./libft/deque \

SRCS = \
main.c \
main_parsing.c \
main_parsing_utils.c \
main_parsing_utils_2.c \
push_swap_a.c \
push_swap_b.c \
push_swap_utils.c \
execute_cmd_a.c \
execute_cmd_a_utils.c \
execute_cmd_b.c \
execute_cmd_b_utils.c \
hard_sorting_a.c \
hard_sorting_three_a.c \
hard_sorting_b.c \
hard_sorting_three_b.c \
data_structures.c \

SRCS_BONUS = \
main_bonus.c \
main_parsing_bonus.c \
main_parsing_utils_bonus.c \
main_parsing_utils_2_bonus.c \
data_structures_bonus.c \
cmd_processor_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./libft/libft/libft.a
PRINTF = ./libft/ft_printf_project/libftprintf.a
GNL = ./libft/get_next_line/get_next_line.a
DEQUE = ./libft/deque/deque.a

EXE = push_swap
EXE_BONUS = checker

all:
	for DIRS in $(SUBDIRS); do \
		$(MAKE) -C $$DIRS; \
	done
	make $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(PRINTF) $(DEQUE) $(GNL)

$(EXE_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(PRINTF) $(DEQUE) $(GNL)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	for DIRS in $(SUBDIRS); do \
		$(MAKE) -C $$DIRS clean; \
	done

fclean: clean
	rm -rf $(EXE) $(EXE_BONUS) $(LIBFT) $(PRINTF) $(DEQUE) $(GNL)

re:
	make fclean
	make all

bonus:
	for DIRS in $(SUBDIRS); do \
		$(MAKE) -C $$DIRS; \
	done
	make $(EXE_BONUS)

.PHONY: all clean fclean re bonus
