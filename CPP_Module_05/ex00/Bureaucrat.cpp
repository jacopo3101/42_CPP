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

Bureaucrat::Bureaucrat() : name("NaN")
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