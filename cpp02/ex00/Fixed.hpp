#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

class Fixed
{
    private :
                int _value;
                const static int _numberBit;

    public :
            Fixed();
            Fixed(const Fixed& other);
            ~Fixed();
            Fixed& operator=(const Fixed& other);
            int getRawBits(void) const;
            void setRawBits(int const raw);
};

#endif