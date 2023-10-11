#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target, std::string name);
    RobotomyRequestForm(RobotomyRequestForm &scForm);
    RobotomyRequestForm& operator=(RobotomyRequestForm const &other);
    void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    ~RobotomyRequestForm();
};