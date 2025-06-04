#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string Name) : _name(Name), _HitPoints(10), 
                                        _EnergyPoints(10), _AttackDamage(2) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
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
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
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
    // std::cout << _EnergyPoints <<  std::endl << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _HitPoints =-amount;
    if(_HitPoints < 0)
        _HitPoints = 0;
    std::cout << "ClapTrap " << _name << " Lose "<< amount << " Hit Points " << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << _HitPoints <<  std::endl << std::endl; 
    if(_EnergyPoints <= 0 || _HitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " Cannot repair itself !" << std::endl;
        return;
    }
    std::cout << "Status — HP: " << _HitPoints << ", Energy: " << _EnergyPoints << std::endl;
    _EnergyPoints--;
    _HitPoints = +amount;
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
