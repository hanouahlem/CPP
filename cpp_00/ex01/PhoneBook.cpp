#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _i = 0;
    _CountContact = 0;
}

PhoneBook::~PhoneBook()
{
    
}

int GoodNumber(std::string phone_number)
{
    int i = 0;
    while(phone_number[i])
    {
        if(!std::isdigit(phone_number[i]))
            return(1);
        i++;
    }
    return(0);
}

void PhoneBook::addContact()
{
    std::string first_name,last_name, nick_name, phone_number, darkest_secret;

    while (1)
    {
        std::cout << "Write your First name : " << std::endl;
        std::getline(std::cin, first_name);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return;
        }
        if(first_name.empty() || first_name == " ")
        {
            std::cout << "Empty input is not allowed. Please type something." << std::endl;
            continue;
        }
        break;
    }

    while (1)
    {
        std::cout << "Write your Last name : " << std::endl;
        std::getline(std::cin, last_name);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return;
        }
        if(last_name.empty() || first_name == " ")
        {
            std::cout << "Empty input is not allowed. Please type something." << std::endl;
            continue;
        }
        break;
    }

    while (1)
    {
        std::cout << "Write your Nick_name : " << std::endl;
        std::getline(std::cin, nick_name);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return;
        }
        if(nick_name.empty() || first_name == " ")
        {
            std::cout << "Empty input is not allowed. Please type something." << std::endl;
            continue;
        }
        break;
    }

    while (1)
    {
        std::cout << "Write your Phone number : " << std::endl;
        std::getline(std::cin, phone_number);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return;
        }
        if(phone_number.empty() || GoodNumber(phone_number) == 1 || first_name == " ")
        {
            std::cout << "Empty input is not allowed. Please type something." << std::endl;
            continue;
        }
        break;
    }

    while (1)
    {
        std::cout << "Write your Darkest secret : " << std::endl;
        std::getline(std::cin, darkest_secret);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return;
        }
        if(darkest_secret.empty() || first_name == " ")
        {
            std::cout << "Empty input is not allowed. Please type something." << std::endl;
            continue;
        }
        break;
    } 
    tab[_i].makeContact(first_name,last_name, nick_name, phone_number, darkest_secret);
    _i = (_i + 1) %8;
    if(_CountContact < 8)
        _CountContact++;
    std::cout << "Your contact has been successfully saved ^_^ " << std::endl;
}
 
void PhoneBook::searchContact()
{
    int i = 0;
    std::string line;
    int index ;

    if(_CountContact == 0)
    {
        std::cout << "No contact is registered, Your PhoneBook is empty !" << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10)<< "First Name" << "|"
              << std::setw(10) << "Last Name" << "|" << std::setw(10)<< " Nick Name" << "|"
              << std::endl;
              std::cout << "___________________________________________" << std::endl;

    while(i < _CountContact)
    {
        tab[i].make_order(i);
        i++;
    }
    std::cout << "If you want a specific contact, type its index: " << std::endl;
    while(1)
    {
        std::getline(std::cin, line);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return;
        }
        std::stringstream ss(line);
        if (!(ss >> index))
        {
            std::cout << "Invalid line. Please enter a number." << std::endl;
            continue;
        }
        if(index < 1 || index > _CountContact)
        {
            std::cout << "Make sure you entered a valid index" << std::endl;
            continue;
        }
        break;
    }
    tab[index - 1].display_the_contact();
}

