#include "Test.hpp"

WrongAnimal::WrongAnimal(){};

WrongAnimal::~WrongAnimal(){};

void WrongAnimal::makeSound() const
{
    std::cout << "generic wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

WrongCat::WrongCat(){
    type = "WrongCat";
}

WrongCat::~WrongCat(){}

void WrongCat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}