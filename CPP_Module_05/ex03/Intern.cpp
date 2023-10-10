#include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makePresidentialPardon(std::string name)
{
    return new PresidentialPardonForm("presidential pardon",name);
}

AForm *Intern::makeRobotomyRequest(std::string name)
{
    return new RobotomyRequestForm("robotomy request", name);
}

AForm *Intern::makeShrubberyCreation(std::string name)
{
    return new ShrubberyCreationForm("shrubbery creation", name);
}

AForm *Intern::makeForm(std::string target, std::string name)
{
    MemberFunctionPtr functionArray[3] = {&Intern::makeShrubberyCreation, &Intern::makePresidentialPardon, &Intern::makeRobotomyRequest};
    std::string targetList[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    for(int i = 0; i < 3; i++)
    {
        if (target.compare(targetList[i]) == 0)
        {
            std::cout << target.compare(targetList[i]) << "\n";
            return functionArray[i](name);
        }
    }
    return NULL;
}
