#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    std::string name1 = "ciro", name2 = "carmine", name3 = "Sergio", name4 = "cane";
    ClapTrap clap1(name1);
    ClapTrap clap2(name2); 
    ScavTrap scav1(name3);
    FragTrap frag1(name4);

    frag1.highFivesGuys();
    scav1.guardGate();
    scav1.attack(name1);
    clap1.attack(name2);
    clap2.takeDamage(3);
    clap2.attack(name1);
    clap1.takeDamage(10);
    clap1.beRepaired(8);
    return 0;
}
