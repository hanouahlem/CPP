#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor called" << std::endl;
}
Dog::Dog(const Dog &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;
}
Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_type = other._type;
    }
    return(*this);
}
Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "Wooouf  Wooouf" << std::endl;
}