#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private :
            std::string _type;
            Brain* _Brain;

    public :
            Dog();
            Dog(const Dog &other);
            Dog &operator=(const Dog &other);
            virtual ~Dog();
            void makeSound() const;
};

#endif