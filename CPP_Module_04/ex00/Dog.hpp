#pragma once
#ifndef DOG_CPP
#define DOG_CPP
#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    void makeSound() const;
};
#endif