
#include <iostream>

int main ()
{
    std::cout << std::endl;
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    std::cout << "The memory address of the string     : " << &string << std::endl; 
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl; 
    std::cout << "The memory address held by stringREF : "<< &stringREF << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "The value of the string variable  : "<< string << std::endl; 
    std::cout << "The value pointed to by stringPTR : "<< *stringPTR << std::endl; 
    std::cout << "The value pointed to by stringREF : "<< stringREF << std::endl;
}



// Pointeur 
// std::cout << *stringPTR << std::endl;     // Affiche le contenu
// std::cout << stringPTR << std::endl;      // Affiche l’adresse mémoire


// Reference
// std::cout << stringREF << std::endl;      // Affiche le contenu
// std::cout << &stringREF << std::endl;     // Affiche l’adresse de str