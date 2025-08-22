#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <iomanip>


class Contact
{
    private : 

        std::string _first_name;
        std::string _last_name;
        std::string _nick_name;
        std::string _phone_number;
        std::string _darkest_secret;

    public : 

        Contact();
        ~Contact();
        void makeContact(std::string FirstName, std::string LastName, std::string NickName, 
            std::string PhoneNumber, std::string DarkestSecret);
        
        void make_order(int i);
        void display_the_contact();
    
};

#endif