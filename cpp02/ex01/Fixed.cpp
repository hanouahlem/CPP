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
    return (this->_value);
}


void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

Fixed::Fixed(int const int_Convert)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = int_Convert * (1 << _numberBit);
}

Fixed::Fixed(float const flt_Convert)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(flt_Convert * (1 << _numberBit));
}

float Fixed::toFloat() const
{
    return(static_cast<float>(this->_value) / (1 << _numberBit));
}

int Fixed::toInt() const
{
    return this->_value / (1 << _numberBit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &result)
{
    out << result.toFloat();
    return out;
}