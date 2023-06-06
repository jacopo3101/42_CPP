#pragma once
#ifndef HumanB_HPP
#define HumanB_HPP
#include <iostream>
#include "Weapon.hpp"
class HumanB{
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& weap);
};
#endif