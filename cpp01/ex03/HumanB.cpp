#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
    this->_nameB = name;
    this->_weapon = NULL;
}
            
HumanB::~HumanB()
{

}
void HumanB::setWeapon(Weapon &newValue)
{
    this->_weapon = &newValue;
}

void HumanB::attack()
{
    if(_weapon)
        std::cout << _nameB <<  " attacks with their " << _weapon->getweapon() << std::endl;
    else
        std::cout << _nameB << " cannot attack without a weapon !! " << std::endl;
}