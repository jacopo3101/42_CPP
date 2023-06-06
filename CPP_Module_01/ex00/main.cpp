#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("pippo");
    zombie->announce();
    randomChump("totti");
    delete zombie;
    return 0;
}
