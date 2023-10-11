#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

    std::string name = "name";
    std::string target = "target";
    AForm *pardon = new PresidentialPardonForm(target, name);
    AForm *shrubbery = new ShrubberyCreationForm(target, name);
    AForm *robotomy = new RobotomyRequestForm(target, name);
    try
    {
        Bureaucrat bur(1, "Gino");
        bur.signForm(*pardon);
        bur.executeForm(*pardon);
        bur.signForm(*shrubbery);
        bur.executeForm(*shrubbery);
        bur.signForm(*robotomy);
        bur.executeForm(*robotomy);
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    delete pardon;
    delete shrubbery;
    delete robotomy;
    return 0;
}