#pragma once
#include "AMateria.hpp"
class Ice : public AMateria
{  
public:
    Ice();
    Ice(const Ice &other);
    Ice& operator=(const Ice &other);
    AMateria* clone() const;
    ~Ice();
};