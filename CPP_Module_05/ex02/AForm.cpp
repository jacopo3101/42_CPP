#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade)
{
    if (executeGrade > 150 || signGrade > 150)
        throw AForm::GradeTooLowException();
    if (executeGrade < 1 || signGrade < 1)
        throw AForm::GradeTooHighException();
    signFlag = false;
}

AForm::AForm(AForm &Aform) : name(Aform.name), signGrade(Aform.signGrade), executeGrade(Aform.executeGrade)
{
    this->signFlag = Aform.signFlag;
}

AForm::~AForm()
{}

AForm::AForm() : name("NaN"), signGrade(150), executeGrade(150)
{}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getSignFlag() const
{
    return signFlag;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecuteGrade() const
{
    return executeGrade;
}

void AForm::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    this->signFlag = true;
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->signFlag = other.getSignFlag();
    return *this;
}

std::ostream& operator<<(std::ostream &out,const AForm &Aform)
{
    out << Aform.getName() << ", " << Aform.getExecuteGrade() << ", " 
        << Aform.getSignGrade() << ", Sign: " << Aform.getSignFlag() << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed!";
}