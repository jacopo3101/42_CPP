#include "Bureaucrat.hpp"

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException(); 
    grade++;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

Bureaucrat::Bureaucrat() : name("NaN"), grade(150)
{}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.getName())
{
    this->grade = bur.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
		this->grade = other.getGrade();
	return *this;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::signForm(AForm &form)
{
    if (form.getSignFlag() == false && form.getSignGrade() > grade)
    {
        form.beSigned(*this);
        std::cout << name << " signed Form: " << form << std::endl;
    }
    else
    {
        if (form.getSignGrade() > grade)
            std::cout << name << " couldn't sign "<< form.getName() <<" because already signed" << std::endl;
        else
            std::cout << name << " couldn't sign "<< form.getName() <<" because grade too low!" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (form.getSignFlag() && form.getExecuteGrade() > grade)
    {
        form.execute(*this);
        std::cout << name << " executed " << form << std::endl;
    }
    else
    {
        if (form.getExecuteGrade() > grade)
            std::cout << name << " couldn't execute "<< form.getName() <<" because it's not signed" << std::endl;
        else
            std::cout << name << " couldn't execute "<< form.getName() <<" because grade too low!" << std::endl;
    }
}

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}