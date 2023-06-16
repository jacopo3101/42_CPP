#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal constructor called" << std::endl;
};

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
};

void Animal::makeSound() const
{
    std::cout << "generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}