#pragma once
#include "ICharacter.hpp"
class AMateria
{
protected:
    std::string type;
public:
    AMateria();
    AMateria(const AMateria &other);
    AMateria(std::string const & type);
    AMateria& operator=(const AMateria &other);
    virtual ~AMateria();
    std::string const &getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};