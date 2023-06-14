#include "ScavTrap.hpp"
int main()
{
    std::string name1 = "ciro", name2 = "carmine", name3 = "Sergio";
    ClapTrap clap1(name1);
    ClapTrap clap2(name2); 
    ScavTrap Scav1(name3);

    Scav1.attack(name1);
    clap1.attack(name2);
    clap2.takeDamage(3);
    clap2.attack(name1);
    clap1.takeDamage(10);
    clap1.beRepaired(8);
    return 0;
}
