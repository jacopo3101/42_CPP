#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target, std::string name) : AForm(name, 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &scForm) : AForm(scForm.getName(), scForm.getSignGrade(), scForm.getExecuteGrade())
{
    this->target = scForm.getTarget();
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("NaN", 150, 150), target("NaN")
{}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
        target = other.getTarget();
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() >= getExecuteGrade())
        throw AForm::GradeTooLowException();
    if (!this->getSignFlag())
        throw AForm::FormNotSignedException();

    std::cout << "\"some drilling noises\"" << std::endl;
    unsigned seed = time(0);// Get the system time.
    srand(seed);// Seed the random number generator.

    if (rand() % 2 < 1)
        std::cout << target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomized failed!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}