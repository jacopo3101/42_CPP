#include "Cat.hpp"
#include "Dog.hpp"

#define MAX_SIZE 20

int main()
{
    Animal *animalList[MAX_SIZE];
    size_t i;

    for (i = 0; i < MAX_SIZE / 2; i++)
        animalList[i] = new Cat();
    for (; i < MAX_SIZE ; i++)
        animalList[i] = new Dog();
    for (i = 0; i < MAX_SIZE; i++)
        delete animalList[i];

    // const Animal* j = new Animal();
    const Animal* k = new Cat();

    // delete j;
    delete k;

    return 0;
}