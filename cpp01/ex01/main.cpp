#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    int N = 4;

    zombie = zombieHorde(N, "Khalid");
    delete[] zombie;
    return(0);
}