CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:%.cpp=%.o)
NAME	= harl

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $^ -o $@
	@echo "Harl2.0 is Created"

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
