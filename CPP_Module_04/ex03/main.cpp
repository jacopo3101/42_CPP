#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    AMateria *bob_tmp;
    bob_tmp = src->createMateria("ice");
    bob->equip(bob_tmp);
    bob_tmp = src->createMateria("cure");
    bob->equip(bob_tmp);

    bob->unequip(1);
    bob->use(0, *me);
    bob->use(1, *me);

    delete bob;
    delete me;
    delete src;

    return 0;
}
