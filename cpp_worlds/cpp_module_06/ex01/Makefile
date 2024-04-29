CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp Serializer.cpp
OBJS	= $(SRCS:%.cpp=%.o)
NAME	= reinterpret

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -o $@ -c $^

clean:
	@rm -rf $(OBJS)

fclean:
	@make clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
