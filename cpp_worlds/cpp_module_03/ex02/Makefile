NAME	= claptrap

SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS	= $(SRCS:srcs/%.cpp=srcs/%.o)

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -I ./includes -o $@ -c $^

clean:
	@rm -rf $(OBJS)

fclean:
	@make clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
