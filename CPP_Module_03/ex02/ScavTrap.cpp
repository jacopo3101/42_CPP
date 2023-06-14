#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &scavtrap) : ClapTrap(scavtrap.name)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->hitPoints = scavtrap.hitPoints;
    this->energyPoints = scavtrap.energyPoints;
    this->energyPoints = scavtrap.energyPoints;
}

ScavTrap& ScavTrap::operator=(ScavTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing "<< attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap deconstructor called" << std::endl;
}