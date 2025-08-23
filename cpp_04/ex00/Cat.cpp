#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->_type = "Cat";
}
Cat::Cat(const Cat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;
}
Cat& Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_type = other._type;
    }
    return(*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miaouuuuu" << std::endl;
}
