#include "Weapon.hpp"

Weapon::Weapon(const std::string type )
{
    this->_type = type;
}

Weapon::~Weapon()
{
    
}

std::string Weapon::getType() const
{
    return(this->_type);
}

void Weapon::setType(std::string newValue)
{
    this->_type = newValue;
}
