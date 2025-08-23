// #include "ClapTrap.hpp"

#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Jack");

    std::cout << "\n=== Basic Actions ===" << std::endl;
    frag.attack("Bandit");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();

    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    FragTrap fragCopy(frag);  // Appelle le constructeur de copie
    fragCopy.attack("Skag");

    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    FragTrap anotherFrag("Clap");
    anotherFrag = frag;  // Appelle l'opérateur d'affectation
    anotherFrag.highFivesGuys();

    std::cout << "\n=== Destruction (end of scope) ===" << std::endl;
    return 0;
}
