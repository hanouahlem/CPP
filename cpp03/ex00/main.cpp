#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Jack");

    a.attack("Bandit");
    a.takeDamage(1);
    a.beRepaired(1);
    a.attack("Skag");
    a.takeDamage(2);
    a.beRepaired(2);
    a.attack("Bandit"); 
    a.beRepaired(3);

    ClapTrap b = a; // Test du constructeur de copie
    ClapTrap c("Zed");
    c = a;          // Test de l'opérateur d'affectation

    return 0;
}
