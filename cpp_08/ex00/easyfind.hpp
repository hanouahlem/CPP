#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception{
    public:
        virtual const char *what() const throw(){
            return ("Value not found!");
        }
        
};

template <typename T>
typename T::iterator easyfind(T& container, int c){
    typename T::iterator index = std::find(container.begin(), container.end(), c);
    if (index == container.end())
        throw ValueNotFoundException();
    return index;
}



// Un conteneur est une structure de données générique fournie par la STL,
// qui stocke et organise des éléments en mémoire.