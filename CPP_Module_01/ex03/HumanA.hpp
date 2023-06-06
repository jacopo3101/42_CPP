#pragma once
#ifndef HumanA_HPP
#define HumanA_HPP
#include <iostream>
#include "Weapon.hpp"
class HumanA{
private:
    std::string name;
    Weapon &weapon;
public:
    HumanA(std::string name, Weapon& weap);
    ~HumanA();
    void attack();
};
#endif