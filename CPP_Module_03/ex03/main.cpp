#include "DiamondTrap.hpp"
int main()
{
    std::string name1 = "ciro",/* name2 = "carmine", name3 = "Sergio", name4 = "cane",*/ name5 = "diamond";
    ClapTrap clap1(name1);
    // ClapTrap clap2(name2); 
    // ScavTrap scav1(name3);
    // FragTrap frag1(name4);
    DiamondTrap diamond1(name5);

    // frag1.highFivesGuys();
    // scav1.guardGate();
    diamond1.attack(name1);
    diamond1.whoAmI();
    // scav1.attack(name1);
    // clap1.attack(name2);
    // clap2.takeDamage(3);
    // clap2.attack(name1);
    clap1.takeDamage(10);
    clap1.beRepaired(8);
    return 0;
}
