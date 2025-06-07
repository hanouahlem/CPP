#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    _HitPoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20; 
    std::cout << "ScavTrap Default constructor " << _name <<" called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor  " << _name << " called" << std::endl;
   
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap Copy assignment operator " << _name << " called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor " << _name << " called" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (_EnergyPoints <= 0 || _HitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " can't attack " << target << "!" << std::endl;
        return;
    }
    _EnergyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"<< std::endl; 
}