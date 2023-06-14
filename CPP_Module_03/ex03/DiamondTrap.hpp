#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
private:
    ClapTrap::name;
public:
    DiamondTrap(std::string &name);
    DiamondTrap(DiamondTrap &diamondtrap);
    DiamondTrap& operator=(DiamondTrap &other);
    void attack(std::string &target);
    void whoAmI();
    ~DiamondTrap();
};
#endif