
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap s1("Guardian");

    std::cout << "\n=== Testing actions ===" << std::endl;
    s1.attack("Bandit");
    s1.takeDamage(30);
    s1.beRepaired(15);
    s1.guardGate();

    std::cout << "\n=== Copy Constructor ===" << std::endl;
    ScavTrap s2(s1);

    std::cout << "\n=== Copy Assignment ===" << std::endl;
    ScavTrap s3("Temp");
    s3 = s1;

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
