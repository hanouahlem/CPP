#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed
{
    private :
                int _value;
                static const int _numberBit;

    public :
            Fixed();
            Fixed(const Fixed& other);
            Fixed(int const int_Convert);
            Fixed(float const flt_Convert);
            ~Fixed();
            Fixed& operator=(const Fixed& other);
            int getRawBits(void) const;
            void setRawBits(int const raw);
            float toFloat( void ) const;
            int toInt( void ) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &result);

#endif