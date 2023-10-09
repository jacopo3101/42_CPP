#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
    RobotomyRequestForm();
public:
    RobotomyRequestForm(std::string target, std::string name);
    RobotomyRequestForm(RobotomyRequestForm &scForm);
    RobotomyRequestForm& operator=(RobotomyRequestForm const &other);
    void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    ~RobotomyRequestForm();
};