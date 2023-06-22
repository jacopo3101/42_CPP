#pragma once
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