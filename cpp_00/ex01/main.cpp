#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook PhoneBook;
    
    while(1)
    {
        std::string line;
        if(std::cin.eof()) 
            return(0);
        std::cout << " Enter your command ADD / SEARCH / EXIT : " << std::endl;
        std::getline(std::cin, line);
        if(std::cin.eof())
        {
            std::cout << "Ciao" << std::endl;
            return 0;
        }
        else if(line.compare("ADD") == 0)
            PhoneBook.addContact();
        else if(line.compare("SEARCH") == 0)
            PhoneBook.searchContact();
        else if(line.compare("EXIT") == 0)
        {
            std::cout << "Ciao" << std::endl;
            exit(0);
        }
        else
            std::cout << "Command not found !" << std::endl;
    }
    return(0);
} 