#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;
}
WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if(this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat " << std::endl;
}