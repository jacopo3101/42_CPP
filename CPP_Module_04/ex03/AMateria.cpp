#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

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
    (void)other;
    return *this;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    if (type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if(type == "cure")
        std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}