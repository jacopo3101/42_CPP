#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog(){
    std::cout << "Brain destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!!" << std::endl;
}