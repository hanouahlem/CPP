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


         // comparison operator overload
        bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
        bool operator<=(Fixed const &other) const;
        bool operator>=(Fixed const &other) const;
        bool operator!=(Fixed const &other) const;
        bool operator==(Fixed const &other) const;

        Fixed operator+(Fixed const &other) const;
        Fixed operator-(Fixed const &other) const;
        Fixed operator*(Fixed const &other) const;
        Fixed operator/(Fixed const &other) const;


        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);


        Fixed &min(Fixed &nbr1, Fixed &nbr2);
        Fixed &max(Fixed &nbr1, Fixed &nbr2);

       static Fixed const &min(Fixed const &nbr1, Fixed const &nbr2);
       static Fixed const &max(Fixed const &nbr1, Fixed const &nbr2);

};
std::ostream &operator<<(std::ostream &out, const Fixed &result);

#endif