#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string &name)
{
    this->name = name;
    std::cout << "DiamondTrap constructor called" << std::endl;
    ClapTrap::name = name.append("_clap_name");
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap &diamondtrap) : ClapTrap(diamondtrap.name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->hitPoints = diamondtrap.hitPoints;
    this->energyPoints = diamondtrap.energyPoints;
    this->attackDamage = diamondtrap.attackDamage;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}


void DiamondTrap::attack(std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "ClapTrap name: " << ClapTrap::name << " name: " << name << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}