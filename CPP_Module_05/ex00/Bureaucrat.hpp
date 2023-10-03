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
    Bureaucrat(int grade, std::string name);
    Bureaucrat(const Bureaucrat &Bureaucrat);
    ~Bureaucrat();
    int getGrade() const;
    std::string getName() const;
    void incrementGrade();
    void decrementGrade();
    Bureaucrat& operator=(const Bureaucrat &other);
};

std::ostream& operator<<(std::ostream &out,const Bureaucrat &bureaucrat);

class GradeTooHighException : public std::exception
{
public:
    const char *whatMsg();
};


class GradeTooLowException : public std::exception
{
public:
    const char *whatMsg();
};