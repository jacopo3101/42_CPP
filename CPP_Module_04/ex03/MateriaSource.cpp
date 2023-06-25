#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::~MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (size_t i = 0; i < 4; i++)
        list[i] = other.list[i]->clone();
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (!list[i])
        {
            return ;
            list[i] = m->clone();
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (list[i]->getType() == type)
            return list[i]->clone();
    }
    return 0;
}