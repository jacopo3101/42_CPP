#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(int grade, std::string name);
    Bureaucrat(const Bureaucrat &Bureaucrat);
    ~Bureaucrat();
    int getGrade() const;
    std::string getName() const;
    void incrementGrade();
    void decrementGrade();
    Bureaucrat& operator=(const Bureaucrat &other);

    //exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out,const Bureaucrat &bureaucrat);