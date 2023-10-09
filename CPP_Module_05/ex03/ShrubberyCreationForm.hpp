#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(std::string target, std::string name);
    ShrubberyCreationForm(ShrubberyCreationForm &scForm);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const &other);
    void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    ~ShrubberyCreationForm();
};