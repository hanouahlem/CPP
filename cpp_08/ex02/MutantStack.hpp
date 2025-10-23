#pragma once

#include <stack>
#include <iostream>


template<typename T>
class MutantStack : public std::stack<T>
{
    public :
            MutantStack(){};
            ~MutantStack(){};
            MutantStack(const MutantStack &other) : std::stack<T>(other){};
            MutantStack &operator=(const MutantStack &other)
            {
                std::stack<T>::operator=(other);
                return *this;
            }
            
            typedef typename std::stack<T>::container_type::iterator iterator;
            typedef typename std::stack<T>::container_type::const_iterator const_iterator;
              
            typename std::stack<T>::container_type::iterator begin()
            {
                return (this->c.begin());
            }
            typename std::stack<T>::container_type::iterator end()
            {
                return (this->c.end());
            }
};
