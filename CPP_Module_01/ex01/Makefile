GCC		= c++

CFLAGS	= -g -Wall -Wextra -Werror -std=c++98

FILES	= Zombie.cpp main.cpp ZombieHorde.cpp

NAME	= horde

RM	= rm -f

OBJECTS=$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(GCC) $(CFLAGS) $(OBJECTS) -o $(NAME)

.cpp.o:
	${GCC} ${CFLAGS} -c $< -o $@

clean:
			@$(RM) $(OBJECTS)
			
fclean:	clean
			@$(RM) $(NAME)
			
re:		fclean all

.PHONY:		all clean fclean re