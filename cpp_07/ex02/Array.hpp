#pragma once

#include <iostream>
#include <string>
#include <unistd.h>

template <typename T>
class Array
{
        private:
                T *_Array;
                unsigned int _size;

        public:
                Array<T>() : _Array(NULL), _size(0)
                {}

                Array<T>(unsigned int n) : _Array(new T[n]()), _size(n)
                {}
    
                Array<T>(const Array<T> &copy) : _Array(new T[copy._size]) ,_size(copy._size)
                {
                        for (unsigned int i = 0; i < _size; i++)
                                _Array[i] = copy._Array[i];
                }

                Array<T> &operator=(Array<T> &copy)
                {
                    if (this != &copy)
                    {
                        delete[] _Array;
                        _size = copy._size;
                        _Array = new T[_size];
                        for (unsigned int i = 0; i < _size; i++)
                            _Array[i] = copy._Array[i];
                    }
                    return(*this);
                }

                ~Array<T>()
                {
                    delete[] _Array;
                }

                T& operator[](unsigned int i)
                {
                    if(i >= _size)
                        throw std::out_of_range(" index is out of bounds");
                    return(_Array[i]);
                }

                const T& operator[](unsigned int i) const
                {
                    if(i >= _size)
                        throw std::out_of_range(" index is out of bounds");
                    return(_Array[i]);
                }

                 unsigned int size() const
                {
                        return (this->_size);
                }
};      