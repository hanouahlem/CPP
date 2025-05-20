#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include <sstream>

class PhoneBook
{
    
    private :

        Contact tab[8];
        int _i;
        int _CountContact;
    
    public :

        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact();

};

#endif