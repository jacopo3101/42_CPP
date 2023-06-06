GCC		= c++

CFLAGS	= -g -Wall -Wextra -Werror

FILES	= main.cpp Harl.cpp

NAME	= harlFilter

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