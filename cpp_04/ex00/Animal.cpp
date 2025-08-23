#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;

}
Animal& Animal::operator=(const Animal &other)
{
    if(this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return(*this);
}
Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Sound Animal" << std::endl;
}

std::string Animal::getType() const 
{
    return(this->_type);
}