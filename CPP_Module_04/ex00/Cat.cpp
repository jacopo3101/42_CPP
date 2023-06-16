#include "Cat.hpp"

Cat::Cat(){
    type = "Cat";
}

Cat::~Cat(){}

void Cat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}