#pragma once
//#include <iostream>
// #include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool signFlag;
    const int signGrade;
    const int executeGrade;
public:
    AForm();
    AForm(std::string name, int signGrade, int executeGrade);
    AForm(AForm &Aform);
    ~AForm();
    std::string getName() const;
    bool getSignFlag() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat &bur);
    AForm& operator=(const AForm &other);
    virtual void execute(Bureaucrat const & executor) const = 0;
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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out,const AForm &Aform);