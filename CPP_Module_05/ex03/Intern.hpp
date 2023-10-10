#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include<string>
class Intern
{
private:
    static AForm *makePresidentialPardon(std::string name);
    static AForm *makeRobotomyRequest(std::string name);
    static AForm *makeShrubberyCreation(std::string name);
public:
    Intern();
    ~Intern();
    AForm *makeForm(std::string name, std::string target);
};

typedef AForm *(*MemberFunctionPtr)(std::string);