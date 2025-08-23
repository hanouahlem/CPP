
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once

#include <iostream>

class WrongAnimal
{
    protected :
               std::string _type;

    public :
               WrongAnimal();
               WrongAnimal(const WrongAnimal &other);
               WrongAnimal &operator=(const WrongAnimal &other);
               ~WrongAnimal();

               void makeSound() const;
               std::string getType() const;
};

#endif