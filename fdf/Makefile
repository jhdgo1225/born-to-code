CC = cc
CFLAGS = -Wall -Wextra -Werror

SUBDIRS = \
./libft/libft \
./libft/ft_printf_project \
./libft/get_next_line \
./mlx \

SRCS = \
main.c \
map_init.c \
map_utils.c \
map_parsing.c \
map_parsing_utils.c \
map_illustrating.c \
map_transforming.c \
map_rotating.c \
map_drawing_lines.c \
map_drawing_lines_utils.c \
map_looping.c \

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft/libft.a
PRINTF = ./libft/ft_printf_project/libftprintf.a
GET_NEXT_LINE = ./libft/get_next_line/get_next_line.a
MINILIBX = ./mlx/libmlx.dylib

EXE = fdf

all:
	for DIRS in $(SUBDIRS); do \
		$(MAKE) -C $$DIRS; \
	done
	make $(EXE)

$(EXE): $(OBJS)
	cp $(MINILIBX) .
	$(CC) $(CFLAGS) $^ -lm -framework OpenGL -framework AppKit $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MINILIBX) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJS)
	for DIRS in $(SUBDIRS); do \
		$(MAKE) -C $$DIRS clean; \
	done

fclean: clean
	rm -rf $(EXE) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MINILIBX) libmlx.dylib

re:
	make fclean
	make all

.PHONY: all clean fclean re
