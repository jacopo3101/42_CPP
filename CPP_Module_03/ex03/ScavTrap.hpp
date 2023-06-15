#pragma once
#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP
#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap
{
protected:
    ScavTrap();
public:
    ScavTrap(std::string &name);
    ScavTrap(ScavTrap &scavtrap);
    ScavTrap& operator=(ScavTrap &other);
    ~ScavTrap();
    void guardGate();
    void attack(std::string &target);
};
#endif