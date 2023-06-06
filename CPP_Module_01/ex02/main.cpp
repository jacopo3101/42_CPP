#include <iostream>
int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << "memory address of the string variable = " << &str << std::endl
        << "memory address held by stringPTR = " << stringPTR << std::endl
        << "memory address held by stringREF = " << &stringREF << std::endl
        << "value of the string variable = " << str << std::endl
        << "value pointed to by stringPTR = " << *stringPTR << std::endl
        << "value pointed to by stringREF = " << stringREF << std::endl;
}