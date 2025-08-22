#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
    this->_name = name;
}

Zombie* newZombie(std::string name)
{
    Zombie *zombie;
    zombie = new Zombie(name);
    return(zombie);
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}