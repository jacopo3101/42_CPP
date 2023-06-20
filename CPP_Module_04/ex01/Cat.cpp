#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat(){
    delete brain;
    std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}