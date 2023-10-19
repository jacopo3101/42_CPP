#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    unsigned seed = time(0);
    srand(seed);
    int n = rand() % 3;
    switch (n)
    {
    case 0:
        return new A();
        break;
    case 1:
        return new B();
        break;
    case 2:
        return new C();
        break;
    default:
        return NULL;
        break;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p) == NULL)
        std::cout << "A type found!" << std::endl;
    else if (dynamic_cast<B*>(p) == NULL)
        std::cout << "B type found!" << std::endl;
    else if (dynamic_cast<C*>(p) == NULL)
        std::cout << "C type found!" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A type found!" << std::endl;
    }
    catch(const std::exception& e)
    {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B type found!" << std::endl;
    }
    catch(const std::exception& e)
    {}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C type found!" << std::endl;
    }
    catch(const std::exception& e)
    {}
}

int main()
{
    Base *basePtr = generate();
    Base &baseRef = *generate();
    identify(baseRef);
    identify(basePtr);
    delete basePtr;
    delete &baseRef;
    return 0;
}
