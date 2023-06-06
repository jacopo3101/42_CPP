#include<iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
using std::string;

PhoneBook::PhoneBook()
{
    next = 0;
    fill = -1;
}

void PhoneBook::addContact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret)
{
    contactList[next] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret, next);
    if (fill < 7)
        fill++;
    if (next == 7)
        next = 0;
    else
        next++;
}

Contact PhoneBook::getContact(int id)
{
    return contactList[id];
}

int PhoneBook::getFill()
{
    return fill;
}