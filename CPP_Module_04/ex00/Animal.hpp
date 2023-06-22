#pragma once
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
};