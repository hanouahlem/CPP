#include "FragTrap.hpp"


FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    _HitPoints = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30; 
    std::cout << "Default constructor Frag called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor Frag called" << std::endl;
   
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "Copy assignment operator Frag called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor Frag called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if(_HitPoints <= 0 || _EnergyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attacks "<< target << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks "<< target << " causing " << _AttackDamage 
        << " points of damage!" << std::endl;
        
    _EnergyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a high five ! ✋" << std::endl;
}