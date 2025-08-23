#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
    _type = "WrongAnimal";
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if(this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_type = other._type;
    }
    return(*this);
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}


void WrongAnimal::makeSound() const
{
    std::cout << "Sound WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return(this->_type);
}