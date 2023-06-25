#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure(){}

Cure::Cure(const Cure &other) : AMateria(other)
{
    type = other.type;
}

Cure& Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure();
}
