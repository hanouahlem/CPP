#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // Test avec vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    
    std::cout << "=== Test vector ===" << std::endl;
    
    try {
        std::vector<int>::iterator index = easyfind(vec, 10);
        std::cout << "Trouvé: " << *index << " Index: " << std::distance(vec.begin(), index)<< std::endl;

        
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }


    try {
        std::vector<int>::iterator index = easyfind(vec, 15);
        std::cout << "Trouvé: " << *index << " Index: " << std::distance(vec.begin(), index)<< std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }


    try {
        easyfind(vec, 99);
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test avec list
    std::list<int> lst;
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(1);
    lst.push_back(25);


    std::cout << "\n=== Test list ===" << std::endl;
    
    try {
        std::list<int>::iterator index = easyfind(lst, 30);
        std::cout << "Trouvé: " << *index << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator index = easyfind(lst, 25);
        std::cout << "Trouvé: " << *index << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

     try {
        std::list<int>::iterator index = easyfind(lst, 5);
        std::cout << "Trouvé: " << *index << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    return 0;
}