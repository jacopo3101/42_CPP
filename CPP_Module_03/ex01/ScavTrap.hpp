#pragma once
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string &name);
    ScavTrap(ScavTrap &scavtrap);
    ScavTrap& operator=(ScavTrap &other);
    ~ScavTrap();
    void guardGate();
    void attack(std::string &target);
};