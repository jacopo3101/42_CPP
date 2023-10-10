GCC		= c++

CFLAGS	= -g -Wall -Wextra -Werror #-std=c++98

FILES	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

NAME	= ex02

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