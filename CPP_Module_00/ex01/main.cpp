#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string truncate(std::string str, size_t size)
{
    if(str.size() >= size)
    {
        return str.substr(0, 9).append(".");
    }else
        return str;
}

bool isInteger(string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void printPhoneBook(PhoneBook phoneBook)
{
    int i = 0;

    while (phoneBook.getFill() >= i)
    {
        Contact contact = phoneBook.getContact(i);
            std::cout << std::right << std::setw(10) << contact.getIndex() << "|"
                << std::right << std::setw(10) << truncate(contact.getFirstName(), 10) << "|"
                << std::right << std::setw(10) << truncate(contact.getLastName(), 10) << "|"
                << std::right << std::setw(10) << truncate(contact.getNickName(), 10) << std::endl;
        i++;
    }
}

void printContact(Contact contact)
{
    std::cout << std::right << "index : " << contact.getIndex() << std::endl
                << std::right << "firstName : " << contact.getFirstName() << std::endl
                << std::right << "lastName : " << contact.getLastName() << std::endl
                << std::right << "nickName : " << contact.getNickName() << std::endl
                << std::right << "darkestSecret : " << contact.getDarkestSecret() << std::endl
                << std::right << "phoneNumber : " << contact.getPhoneNumber() << std::endl;
}

int checkStr(string str)
{
    if(!str.empty() && !(str.find_first_not_of(' ') == std::string::npos))
        return 1;
    else
    {
        std::cout << "Empty string! Contact refused." << std::endl;
        return 0;
    }
}

int main()
{
    PhoneBook phonebook = PhoneBook();
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string secret;
    std::string phoneNumber;
    std::string str;
    std::string str_index;
    Contact contact;
    int index;
    while (1)
    {
        std::cout << "insert ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, str);
        if (str == "ADD")
        {
            std::cout << "insert the first name:" << std::endl;
            std::getline(std::cin, firstName);
            if (!checkStr(firstName))
                continue;
            std::cout << "insert the last name:" << std::endl;
            std::getline(std::cin, lastName);
            if (!checkStr(lastName))
                continue;
            std::cout << "insert the nickname:" << std::endl;
            std::getline(std::cin, nickName);
            if (!checkStr(nickName))
                continue;
            std::cout << "insert the darkest secret:" << std::endl;
            std::getline(std::cin, secret);
            if (!checkStr(secret))
                continue;
            std::cout << "insert the phone number:" << std::endl;
            std::getline(std::cin, phoneNumber);
            if (!checkStr(phoneNumber))
                continue;
            phonebook.addContact(firstName, lastName, nickName, phoneNumber, secret);
        }
        if (str == "SEARCH")
        {
            printPhoneBook(phonebook);
            std::cout << "insert index:" << std::endl;
            std::getline(std::cin, str_index);
            if (!isInteger(str_index))
            {
                std::cout << "invalid index: integer required." << std::endl;
                continue;
            }
            index = std::atoi(str_index.c_str());
            if (index >= 0 && index <= 7 && phonebook.getFill() >= index)
            {
                printContact(phonebook.getContact(index));
            }
            else
                std::cout << "invalid index" << std::endl;
        }
        if (str == "EXIT")
            break;
    }
    return 0;
}
