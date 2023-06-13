#pragma once
#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string &name);
    ~ScavTrap();
    void guardGate();
};
#endif