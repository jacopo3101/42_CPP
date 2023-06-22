#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria &other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return *this;
}