#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string &name);
    FragTrap(FragTrap &fragtrap);
    ~FragTrap();
    FragTrap& operator=(FragTrap &other);
    void highFivesGuys(void);
};
#endif