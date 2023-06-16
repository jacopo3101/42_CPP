#pragma once
#ifndef CAT_CPP
#define CAT_CPP
#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    void makeSound() const;

};
#endif