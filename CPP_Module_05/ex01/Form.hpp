#pragma once
// #include <iostream>
// #include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool signFlag;
    const int signGrade;
    const int executeGrade;
public:
    Form(std::string name, int signGrade, int executeGrade);
    Form(Form &form);
    ~Form();
    std::string getName() const;
    bool getSignFlag() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat &bur);
    Form& operator=(const Form &other);
    // assignement

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

std::ostream& operator<<(std::ostream &out,const Form &form);