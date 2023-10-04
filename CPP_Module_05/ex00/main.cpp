#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat bur(3, "mario");
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