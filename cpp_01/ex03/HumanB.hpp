#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private :
             std::string _nameB;
             Weapon *_weapon;

    public : 
            HumanB(std::string name);
            ~HumanB();
            void setWeapon(Weapon &_weapon);
            void attack();

};




#endif