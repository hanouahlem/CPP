#include "Fixed.hpp"

const int Fixed::_numberBit = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
// Constructeur de recopie
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Surcharge de l’opérateur d’affectation
Fixed& Fixed:: operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->_value  = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}


void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}