#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = newZombie("Khalid");
    zombie->announce();
    randomChump("O'Hazard");
    delete zombie;
}