#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int N = std::atoi(av[1]);
        std::string name = "totti";
        Zombie *horde = zombieHorde(N, name);
        for(int i = 0; i < N; i++)
            horde[i].announce();
        delete[] horde;
    }
    return 0;
}
