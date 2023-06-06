#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weap) : weapon(weap)
{
    this->name = name;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{}
