#include "Dog.hpp"

Dog::Dog(){
    type = "Dog";
}

Dog::~Dog(){}

void Dog::makeSound() const
{
    std::cout << "Woof!!" << std::endl;
}