#pragma once
#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    void makeSound() const;
};
#endif