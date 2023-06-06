#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include<iostream>
#include "Contact.hpp"
using std::string;

class PhoneBook{
private:
    int next;
    int fill;
    Contact contactList[8];
public:
    PhoneBook();
    void addContact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret);
    Contact getContact(int id);
    int getFill();
};

#endif