#include <iostream>
#include <Array.hpp>
#include <stdlib.h>


int main()
{ 
    Array<int> empty;
    Array<int> tab(5);
    std::cout << "Taille vide: " << empty.size() << ", Taille tab: " << tab.size() << std::endl;
    
    // Remplissage et affichage
    for (unsigned int i = 0; i < tab.size(); i++)
        tab[i] = i * 10;
    std::cout << "Contenu tab: ";
    for (unsigned int i = 0; i < tab.size(); i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    // Test copie profonde
    Array<int> copy(tab);
    copy[0] = 25;
    std::cout << "Original[0]: " << tab[0] <<  std::endl;
    std::cout << "Apres copie profonde : " << copy[0] << std::endl;
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    // Test opérateur =
    Array<int> tab2(3);
    tab2 = tab;
    std::cout << "Après affectation : " << std::endl;
    for (unsigned int i = 0; i < tab2.size(); i++)
        std::cout << tab2[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    // Test exception
    try {
        tab[100] = 42;
    }
    catch (std::exception &e) {
        std::cout << "Error : " << e.what() << std::endl;
    }

    return 0;
}