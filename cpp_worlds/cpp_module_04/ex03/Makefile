NAME	= magic

SRCS	= srcs/ICharacter.cpp \
		  srcs/Character.cpp \
		  srcs/AMateria.cpp \
		  srcs/Ice.cpp \
		  srcs/Cure.cpp \
		  srcs/UnusedMateriaCollector.cpp \
		  srcs/IMateriaSource.cpp \
		  srcs/MateriaSource.cpp \
		  srcs/main.cpp

OBJS	= $(SRCS:%.cpp=%.o)

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
