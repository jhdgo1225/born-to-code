NAME	= phonebook

DIR		= srcs
SRCS	= main.cpp Contact.cpp PhoneBook.cpp
OBJS	= $(SRCS:%.cpp=%.o)

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $^ -o $@
	@echo "PhoneBook is made! 📔"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean:
	@make clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
