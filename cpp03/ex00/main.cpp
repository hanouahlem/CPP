#include "ClapTrap.hpp"

// int main()
// {
//     ClapTrap clapA("A");
//     ClapTrap clapB("B");
//     clapA.attack("B");
//     clapB.takeDamage(2);
//     clapB.beRepaired(1);

//     return(0);
// }

int main() {
    ClapTrap a("Jack");

    a.attack("Bandit");
    a.takeDamage(3);
    a.beRepaired(5);
    a.attack("Skag");
    a.takeDamage(12); // Il meurt
    a.beRepaired(12);
    a.attack("Bandit"); // Ne peut plus attaquer
    a.beRepaired(3);   // Ne peut plus se réparer

    ClapTrap b = a; // Test du constructeur de copie
    ClapTrap c("Zed");
    c = a;          // Test de l'opérateur d'affectation

    return 0;
}
