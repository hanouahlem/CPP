#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _nameA(name), _weapon(weapon)
{
    
}
            
HumanA::~HumanA()
{

}

void HumanA::attack()
{
    std::cout << _nameA <<  " attacks with their " << _weapon.getType() << std::endl;
}