#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
    std::string _name;
    int _HitPoints;
    int _EnergyPoints;
    int _AttackDamage;

    public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string GetName()const ;
    int GetHitPoints()const;
    int GetEnergyPoints()const;
    int GetAttackDamage()const;
};

#endif