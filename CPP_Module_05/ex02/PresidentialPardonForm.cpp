#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target, std::string name) : AForm(name, 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &scForm) : AForm(scForm.getName(), scForm.getSignGrade(), scForm.getExecuteGrade())
{
    this->target = scForm.getTarget();
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("NaN", 150, 150), target("NaN")
{}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
        target = other.getTarget();
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() >= getExecuteGrade())
        throw AForm::GradeTooLowException();
    if (!this->getSignFlag())
        throw AForm::FormNotSignedException();
    std::cout << target << "has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}