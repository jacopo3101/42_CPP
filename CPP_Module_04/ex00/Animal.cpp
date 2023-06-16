#include "Animal.hpp"

Animal::Animal(){};

Animal::~Animal(){};

void Animal::makeSound() const
{
    std::cout << "generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}