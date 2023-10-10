#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
private:
    AForm *makePresidentialPardon(std::string name);
    AForm *makeRobotomyRequest(std::string name);
    AForm *makeShrubberyCreation(std::string name);
public:
    Intern();
    ~Intern();
    AForm *makeForm(std::string name, std::string target);
};  