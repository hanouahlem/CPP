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
        std::cout << _nameB <<  " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _nameB << " attack without a weapon but one has fists !! " << std::endl;
}