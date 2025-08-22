#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    int i = 0;
    Zombie *zombieHorde;
    zombieHorde = new Zombie[N];
    while (i < N)
    {
        zombieHorde[i].setName(name);
        std::cout << "Zombie created : " << name << std::endl;
        zombieHorde[i].announce();
        i++;
    }
    return(zombieHorde);
}