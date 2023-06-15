#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class FragTrap : virtual public ClapTrap
{
protected:
    FragTrap();
public:
    FragTrap(std::string &name);
    FragTrap(FragTrap &fragtrap);
    ~FragTrap();
    FragTrap& operator=(FragTrap &other);
    void highFivesGuys(void);
};
#endif