#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    private :
            std::string _type;

    public :
            Cat();
            Cat(const Cat &other);
            Cat &operator=(const Cat &other);
            virtual ~Cat();
            void makeSound()const;
};

#endif