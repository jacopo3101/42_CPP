#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
using std::string;
class Contact
{
private:
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string darkestSecret;
    int index;
public:
    Contact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret, int index);
    Contact();

    string getFirstName();
    string getLastName();
    string getNickName();
    string getPhoneNumber();
    string getDarkestSecret();
    int getIndex();
};

#endif