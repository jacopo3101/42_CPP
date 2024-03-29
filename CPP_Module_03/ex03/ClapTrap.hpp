#pragma once
#include <iostream>
class ClapTrap
{
protected:
	ClapTrap();
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &claptrap);
	~ClapTrap();
	ClapTrap& operator=(ClapTrap &claptrap);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};