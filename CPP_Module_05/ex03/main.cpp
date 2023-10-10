#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

    try
    {
        Bureaucrat bur(10, "Gino");
        std::string name = "name";
        std::string target = "target";
        AForm *pardon = new PresidentialPardonForm(target, name);
        AForm *shrubbery = new ShrubberyCreationForm(target, name);
        AForm *robotomy = new RobotomyRequestForm(target, name);
        robotomy->beSigned(bur);
        bur.signForm(*robotomy);
        robotomy->execute(bur);
        pardon->beSigned(bur);
        bur.signForm(*pardon);
        pardon->execute(bur);        
        shrubbery->beSigned(bur);
        bur.signForm(*shrubbery);
        shrubbery->execute(bur);
    }
    catch(AForm::GradeTooHighException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}