#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->_Brain = new Brain();
}
Cat::Cat(const Cat &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_type = other._type;
    this->_Brain = new Brain();
}
Cat& Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete _Brain;
        this->_Brain = new Brain();
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miaouuuuu Miaouuuuu" << std::endl;
}
