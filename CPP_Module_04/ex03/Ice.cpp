#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice(){}

Ice::Ice(const Ice &other) : AMateria(other)
{
    type = other.type;
}

Ice& Ice::operator=(const Ice &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice();
}