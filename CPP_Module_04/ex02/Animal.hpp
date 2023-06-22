#pragma once
#include <iostream>
#include "Brain.hpp"
class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    virtual void makeSound() const = 0;
    std::string getType() const;
};