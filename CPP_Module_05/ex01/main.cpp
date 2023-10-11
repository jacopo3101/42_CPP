#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat bur(3, "mario");
        Bureaucrat bur1(96, "ciro");
        Form form1("list A", 56, 89);
        bur.signForm(form1);
        bur1.signForm(form1);
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