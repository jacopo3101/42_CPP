#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat bur(3, "mario");
        Form form1("list A", 56, 89);
        bur.signForm(form1);
        form1.beSigned(bur);
        bur.signForm(form1);
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        std::cout << bur <<std::endl;
        bur.incrementGrade();
        bur.decrementGrade();
        std::cout << bur <<std::endl;
        bur.decrementGrade();
        std::cout << bur <<std::endl;
        bur.decrementGrade();
    }catch(Bureaucrat::GradeTooHighException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}