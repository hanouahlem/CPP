#ifndef WEAPON_HPP 
#define WEAPON_HPP

#include <iostream>


class Weapon
{
    private :
             std::string _type;

    public : 
            Weapon(std::string type);
            ~Weapon();
            std::string getweapon() const;
            void setType(std::string newValue);

};


#endif



