#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
        
}

Contact::~Contact()
{

}

void Contact::makeContact(std::string FirstName, std::string LastName, std::string NickName, 
        std::string PhoneNumber, std::string DarkestSecret)
{
    this->_first_name = FirstName;
    this->_last_name = LastName;
    this->_nick_name = NickName;
    this->_phone_number = PhoneNumber;
    this->_darkest_secret = DarkestSecret;
}

void Contact::make_order(int i)
{
    std::cout << std::setw(10) << i + 1 << "|";

    if(_first_name.length() > 10)
    {
        std::cout << std::setw(10);
        std::cout << _first_name.substr(0,9) + ".";
    }
    else
        std::cout << std::setw(10) <<_first_name;
    std::cout << "|";
    if(_last_name.length() > 10)
    {
        std::cout << std::setw(10);
        std::cout << _last_name.substr(0,9) + ".";
    }
    else
        std::cout << std::setw(10) <<_last_name;
    std::cout << "|";
    if(_nick_name.length() > 10)
    {
        std::cout << std::setw(10);
        std::cout << _nick_name.substr(0,9) + ".";
    }
    else
         std::cout << std::setw(10) <<_nick_name;
    std::cout << std::endl;
}

void Contact::display_the_contact()
{
    std::cout << "First Name : " << _first_name << std::endl;
    std::cout << "Last Name : " << _last_name << std::endl;
    std::cout << "Nick Name : " << _nick_name << std::endl;
    std::cout << "Phone number : " << _phone_number << std::endl;
    std::cout << "Darkest secret : " << _darkest_secret << std::endl;
}
