#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once
#include <iostream>

class Animal
{
    protected :
               std::string _type;

    public :
               Animal();
               Animal(const Animal &other);
               Animal &operator=(const Animal &other);
               virtual ~Animal();

               virtual void makeSound() const;
               std::string getType() const;
};

#endif
