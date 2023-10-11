#include "Bureaucrat.hpp"
int main()
{
    Bureaucrat bur1(3, "mario");
    Bureaucrat bur2(145, "ciro");
    try
    {
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
        std::cout << bur1 <<std::endl;
        bur1.incrementGrade();
    }catch(Bureaucrat::GradeTooHighException &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
        std::cout << bur2 <<std::endl;
        bur2.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}