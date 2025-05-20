#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie Random(name);
    Random.announce();
}