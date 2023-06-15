#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap(std::string &name);
    DiamondTrap(DiamondTrap &diamondtrap);
    DiamondTrap& operator=(DiamondTrap &other);
    void attack(std::string &target);
    void whoAmI();
    ~DiamondTrap();
};
#endif