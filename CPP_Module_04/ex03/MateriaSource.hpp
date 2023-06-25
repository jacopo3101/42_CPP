#pragma once
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
    AMateria *list[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};