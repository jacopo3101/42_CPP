#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat bur(3, "mario");
        bur.incrementGrade();
        bur.incrementGrade();
        bur.incrementGrade();
        bur.incrementGrade();
        bur.incrementGrade();
        bur.incrementGrade();
        bur.incrementGrade();
        bur.decrementGrade();
        bur.decrementGrade();
        bur.decrementGrade();
    }catch(GradeTooHighException &ex)
    {
        std::cout << ex.whatMsg() << std::endl;
    }
    catch(GradeTooLowException &e)
    {
        std::cout << e.whatMsg() << std::endl;
    }
    return 0;
}