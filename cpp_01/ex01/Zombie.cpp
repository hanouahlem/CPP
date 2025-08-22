#include "Zombie.hpp"

Zombie::Zombie()
{
}
Zombie::~Zombie()
{
    std::cout << "Zombie destructor : " << _nameZ << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << _nameZ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
    this->_nameZ = name;
}