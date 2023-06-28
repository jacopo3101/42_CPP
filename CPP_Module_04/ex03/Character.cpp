#include "Character.hpp"

Character::Character() : inventory()
{
    name = "";
}

Character::Character(const Character &other) : inventory()
{
    this->name = other.name;
    for (size_t i = 0; i < 4; i++)
        inventory[i] = other.inventory[i]->clone();
}

Character::Character(const std::string &name) : inventory()
{
    this->name = name;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->name = other.name;
        swapInventory(*this, other);
    }
    return *this;
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
    if (inventory[idx] && idx >= 0 && idx <= 3 )
    {
        delete inventory[idx];
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (inventory[idx] != 0)
    {
        if (inventory[idx] && idx >= 0 && idx <= 3)
            inventory[idx]->use(target);
    }
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