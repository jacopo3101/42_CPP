#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];
    AMateria* getAmateria(int idx);
    void swapInventory(Character &curr, const Character &other);
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    std::string const &getName() const;
    ~Character();
};