CXX		= c++

CFLAGS	= -g -Wall -Wextra -Werror -std=c++98

FILES	= main.cpp Contact.cpp PhoneBook.cpp

NAME	= phoneBook

RM	= rm -f

OBJECTS=$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(CXX) $(CFLAGS) $(OBJECTS) -o $(NAME)

.cpp.o:
	${CXX} ${CFLAGS} -c $< -o $@

clean:
			@$(RM) $(OBJECTS)
			
fclean:	clean
			@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re