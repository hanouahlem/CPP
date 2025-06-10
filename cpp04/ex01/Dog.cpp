#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->_Brain = new Brain();
}
Dog::Dog(const Dog &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;
    this->_Brain = new Brain(*other._Brain);
}
Dog& Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete _Brain;
        _Brain = new Brain();
    }
    std::cout << "Copy assignment operator called" << std::endl;
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