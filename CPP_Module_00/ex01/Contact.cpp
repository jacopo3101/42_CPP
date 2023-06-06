#include <iostream>
#include "Contact.hpp"

using std::string;

Contact::Contact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret, int index)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
    this->index = index;
}

Contact::Contact(){}

string Contact::getDarkestSecret()
{
    return darkestSecret;
}
string Contact::getFirstName()
{
    return firstName;
}
string Contact::getLastName()
{
    return lastName;
}
string Contact::getPhoneNumber()
{
    return phoneNumber;
}
string Contact::getNickName()
{
    return nickName;
}
int Contact::getIndex()
{
    return index;
}