#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
private:
    Brain *brain;
public:
    Dog();
    ~Dog();
    void makeSound() const;
};