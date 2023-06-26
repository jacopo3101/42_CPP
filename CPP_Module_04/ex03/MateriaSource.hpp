#pragma once
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
    AMateria *list[4];
    void swapList(MateriaSource &curr, const MateriaSource &other);
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &other);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};