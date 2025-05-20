#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << "Zombie created : " << _name << std::endl;
}
Zombie::~Zombie()
{
    std::cout << "Zombie destructor : " << _name << std::endl;

}