#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : list()
{}

MateriaSource::MateriaSource(const MateriaSource &other) : list()
{
    for (size_t i = 0; i < 4; i++)
        list[i] = other.list[i]->clone();
}

MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < 4; i++)
    {
        if (this->list[i])
            delete this->list[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
        swapList(*this, other);
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (!list[i])
        {
            list[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (list[i] && list[i]->getType() == type)
            return list[i]->clone();
    }
    return 0;
}

void MateriaSource::swapList(MateriaSource &curr, const MateriaSource &other)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (curr.list[i])
            delete curr.list[i];
    }
    for (size_t i = 0; i < 4; i++)
        curr.list[i] = other.list[i]->clone();
}