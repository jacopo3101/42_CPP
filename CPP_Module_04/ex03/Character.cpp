#include "Character.hpp"

Character::Character()
{
    name = "";
}

Character::Character(const Character &other)
{
    this->name = other.name;
    for (size_t i = 0; i < 4; i++)
        inventory[i] = other.inventory[i]->clone();
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->name = name;
        swapInventory(*this, other);
    }
    return *this;
}

Character::Character(const std::string &name)
{
    this->name = name;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3 && inventory[idx])
        delete inventory[idx];
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && inventory[idx])
        inventory[idx]->use(target);
}

AMateria *Character::getAmateria(int idx)
{
    return inventory[idx];
}

void Character::swapInventory(Character &curr, const Character &other)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (curr.inventory[i])
            delete curr.inventory[i];
    }
    for (size_t i = 0; i < 4; i++)
        curr.inventory[i] = other.inventory[i]->clone();
}

Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}