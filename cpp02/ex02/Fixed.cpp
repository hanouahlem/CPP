#include "Fixed.hpp"

const int Fixed::_numberBit = 8;

Fixed::Fixed() : _value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}
// Constructeur de recopie
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}
// Surcharge de l’opérateur d’affectation
Fixed &Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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
    this->_value = int_Convert * (1 << _numberBit);
}

Fixed::Fixed(float const flt_Convert)
{
    this->_value = roundf(flt_Convert * (1 << _numberBit));
}

float Fixed::toFloat() const
{
    return (static_cast<float>(this->_value) / (1 << _numberBit));
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

/**************************************************************/
/**************************************************************/

bool Fixed::operator>(Fixed const &other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(Fixed const &other) const
{
    return (this->_value < other._value);
}

bool Fixed::operator>=(Fixed const &other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(Fixed const &other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator!=(Fixed const &other) const
{
    return (this->_value != other._value);
}

bool Fixed::operator==(Fixed const &other) const
{
    return (this->_value == other._value);
}

/**************************************************************/
/**************************************************************/

Fixed Fixed::operator+(Fixed const &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(Fixed const &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(Fixed const &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(Fixed const &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

/**************************************************************/
/**************************************************************/

Fixed &Fixed::operator++()
{
    this->_value++;
    return (*this);
}

Fixed &Fixed::operator--()
{
    this->_value--;
    return (*this);
}

// pre decrementatioon i++ et ++i
Fixed Fixed::operator++(int)
{
    Fixed tomp = *this;
    this->_value++;
    return (tomp);
} 

Fixed Fixed::operator--(int)
{
    Fixed tomp = *this;
    this->_value--;
    return (tomp);
}

/**************************************************************/
/**************************************************************/

Fixed &Fixed::min(Fixed &nbr1, Fixed &nbr2)
{
    if (nbr1.getRawBits() < nbr2.getRawBits())
        return (nbr1);
    return (nbr2);
}

Fixed &Fixed::max(Fixed &nbr1, Fixed &nbr2)
{
    if (nbr1.getRawBits() > nbr2.getRawBits())
        return (nbr1);
    return (nbr2);
}

Fixed const &Fixed::min(Fixed const &nbr1, Fixed const &nbr2)
{
    if (nbr1.getRawBits() < nbr2.getRawBits())
        return (nbr1);
    return (nbr2);
}

Fixed const &Fixed::max(Fixed const &nbr1, Fixed const &nbr2) 
{
     if(nbr1.getRawBits() > nbr2.getRawBits())
        return(nbr1);
    return(nbr2);
}