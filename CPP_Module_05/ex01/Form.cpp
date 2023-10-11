#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade)
{
    if (executeGrade > 150 || signGrade > 150)
        throw Form::GradeTooLowException();
    if (executeGrade < 1 || signGrade < 1)
        throw Form::GradeTooHighException();
    signFlag = false;
}

Form::Form(Form &form) : name(form.name), signGrade(form.signGrade), executeGrade(form.executeGrade)
{
    this->signFlag = form.signFlag;
}

Form::Form() : name("NaN"), signGrade(150), executeGrade(150)
{}

Form::~Form(){}

std::string Form::getName() const
{
    return name;
}

bool Form::getSignFlag() const
{
    return signFlag;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecuteGrade() const
{
    return executeGrade;
}

void Form::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    this->signFlag = true;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        this->signFlag = other.getSignFlag();
    return *this;
}

std::ostream& operator<<(std::ostream &out,const Form &form)
{
    out << form.getName() << ", " << form.getExecuteGrade() << ", " 
        << form.getSignGrade() << ", Sign: " << form.getSignFlag() << std::endl;
    return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}