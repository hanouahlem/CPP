#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name) : _name(Name), _HitPoints(10), 
                                        _EnergyPoints(10), _AttackDamage(0) 
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->_name = other._name;
    this->_HitPoints = other._HitPoints;
    this->_EnergyPoints = other._HitPoints;
    this->_AttackDamage = other._AttackDamage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        this->_name = other.GetName();
        this->_HitPoints = other.GetHitPoints();
        this->_EnergyPoints = other.GetEnergyPoints();
        this->_AttackDamage = other.GetAttackDamage();
    }
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(_HitPoints <= 0 || _EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attacks "<< target << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks "<< target << " causing " << _AttackDamage 
        << " points of damage!" << std::endl;
        
    _EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _HitPoints -=amount;
    if(_HitPoints < 0)
        _HitPoints = 0;
    std::cout << "ClapTrap " << _name << " Lose "<< amount << " Hit Points " << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(_EnergyPoints <= 0 || _HitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " Cannot repair itself !" << std::endl;
        return;
    }
    _EnergyPoints--;
    _HitPoints += amount;
    std::cout << "ClapTrap " << _name << " Repaired " << amount << " Hit Points" << std::endl;
}



std::string ClapTrap::GetName() const
{
    return(this->_name);
}

int ClapTrap::GetHitPoints() const
{
    return(this->_HitPoints);
}

int ClapTrap::GetEnergyPoints() const
{
    return(this->_EnergyPoints);
}

int ClapTrap::GetAttackDamage() const
{
    return(this->_AttackDamage);
}
