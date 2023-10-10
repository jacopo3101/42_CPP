#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
    PresidentialPardonForm();
public:
    PresidentialPardonForm(std::string target, std::string name);
    PresidentialPardonForm(PresidentialPardonForm &scForm);
    PresidentialPardonForm& operator=(PresidentialPardonForm const &other);
    void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    ~PresidentialPardonForm();
};