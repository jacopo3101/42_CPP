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
    // if (form.getSignFlag() == false)
    // {
    //     std::cout << name << " couldn't sign "<< form.getName() <<" because ";
    //     if (form.getExecuteGrade() < grade)
    //         std::cout << "grade too low!" << std::endl;
    //     else
    //         std::cout << "form can't be signed!" << std::endl;
    // }
    // else
    // {
    //     std::cout << *this << std::endl << "Form: " << form;
    // }
    if (form.getSignFlag() == false && form.getExecuteGrade() >= grade)
    {
        std::cout << *this << std::endl << "Form: " << form;
        form.beSigned(*this);
    }
    else
    {
        if (form.getExecuteGrade() >= grade)
            std::cout << name << " couldn't sign "<< form.getName() <<" because already signed" << std::endl;
        else
            std::cout << name << " couldn't sign "<< form.getName() <<" because grade too low!" << std::endl;

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