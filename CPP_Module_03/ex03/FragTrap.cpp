#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &fragtrap) : ClapTrap(fragtrap.name)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->hitPoints = fragtrap.hitPoints;
    this->energyPoints = fragtrap.energyPoints;
    this->attackDamage = fragtrap.attackDamage;
}

FragTrap& FragTrap::operator=(FragTrap &other)
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

void FragTrap::highFivesGuys()
{
    std::cout << name << " make a positive high five request" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap deconstructor called" << std::endl;
}