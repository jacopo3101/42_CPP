#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{

    
    Intern someRandomIntern;
    AForm* rrf;
    AForm* rForm;
    Bureaucrat *b;
    Bureaucrat *b1;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Shrubbery_form");
    rForm = someRandomIntern.makeForm("robotomy request", "Bender");
    try
    {   
        b = new Bureaucrat(2, "ginpo");
        b1 = new Bureaucrat(100, "gino");
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what();
    }

    try
    {   
        Bureaucrat b(2, "ginpo");
        Bureaucrat b1(100, "gino");
        b1.signForm(*rrf);
        b.signForm(*rrf);
        b.executeForm(*rrf);
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what();
    }
    try
    {
        b1->signForm(*rForm);
        b1->executeForm(*rForm);
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what();
    }
    delete b;
    delete b1;
    delete rrf;
    delete rForm;
    return 0;
}