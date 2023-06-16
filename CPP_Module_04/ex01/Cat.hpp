#pragma once
#ifndef CAT_CPP
#define CAT_CPP
#include "Animal.hpp"

class Cat : public Animal
{
private:
    Brain *brain;
public:
    Cat();
    ~Cat();
    void makeSound() const;

};
#endif