#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	this->name = name;
}

ClapTrap::ClapTrap(ClapTrap &claptrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	if(this != &other)
	{
		this->attackDamage = other.attackDamage;
		this->name = other.name;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
	}
		return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing "<< attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " has been repaired of " << amount << " HP, the new amount is ";
		hitPoints += amount;
		energyPoints--;
		std::cout << hitPoints << " HP!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " take " << amount << " damage, the new HP amount is ";
		hitPoints -= amount;
		std::cout << hitPoints << " HP!" << std::endl;
	}
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}