#ifndef WEAPON_HPP 
#define WEAPON_HPP

#include <iostream>


class Weapon
{
    private :
             std::string _type;

    public : 
            Weapon(const std::string type);
            ~Weapon();
            std::string getType() const;
            void setType(std::string newValue);

};


#endif



