#pragma once
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string &name);
    FragTrap(FragTrap &fragtrap);
    ~FragTrap();
    FragTrap& operator=(FragTrap &other);
    void highFivesGuys(void);
};