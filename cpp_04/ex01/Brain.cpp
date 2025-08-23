#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}
Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = other._ideas[i];
}
Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->_ideas[i] = other._ideas[i];
    }
    return(*this);
}
Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}


