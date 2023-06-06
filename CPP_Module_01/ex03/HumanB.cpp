#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    // weapon = NULL;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weap)
{
    weapon = &weap;
}

HumanB::~HumanB()
{}