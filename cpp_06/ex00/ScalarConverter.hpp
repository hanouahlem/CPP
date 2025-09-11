#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <string>

class ScalarConverter
{
    private :
                ScalarConverter();
                ScalarConverter(ScalarConverter const &other);
                ScalarConverter	&operator=(const ScalarConverter &other);
                ~ScalarConverter();

    public :
                static void  convert(std::string literal);
};
#endif