#include "Cat.hpp"
#include "Dog.hpp"
#include "Test.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();


    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongAnimal->makeSound();

    delete meta;
    delete i;
    delete j;
    delete wrongAnimal;
    delete wrongCat;
    
    return 0;
}