#include "ScalarConverter.hpp"
#include <cmath>

#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter()
{
    // std::cout << "Constructor ScalarConverter has called" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
    // std::cout << "Destructor ScalarConverter has called" << std::endl;
}
ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::convert(std::string literal)
{
    // int resultInt = 0;
    float resultFloat = 0;
    double resultDouble = 0;
    char resultChar = 0;

    if (literal.empty())
    {
        std::cout << "Error: Empty string" << std::endl;
        return;
    }
    for (int i = 0; (size_t)i < literal.length(); i++)
    {
        if (literal.length() == 1 && !std::isdigit(literal[0]))
        {
            char c = literal[0];
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
            return;
        }
        if (!std::isdigit(literal[i]) && !std::isdigit(literal[i + 1]) && literal[i] != '.' && literal[i] != 'f')
        {
            std::cout << "int : impossible" << std::endl;
            std::cout << "char : impossible" << std::endl;
            if (literal == "nan" || literal == "nanf")
                std::cout << "float : nanf" << std::endl;
            else if (literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff")
                std::cout << "float : " << literal[0] << "inff" << std::endl;
            else if (literal == "inf" || literal == "inff")
                std::cout << "float : inff" << std::endl;
            else
                std::cout << "float : impossible" << std::endl;

            if (literal == "nan" || literal == "nanf")
                std::cout << "double : nan" << std::endl;
            else if (literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff")
                std::cout << "double : " << literal[0] << "inf" << std::endl;
            else if (literal == "inf" || literal == "inff")
                std::cout << "double : inf" << std::endl;
            else
                std::cout << "double : impossible" << std::endl;
            return;
        }


        // Parsing
        int dotCount = 0;
        int countF = 0;
        for (size_t i = 0; i < literal.length(); ++i)
        {
            if (literal[i] == '.')
                dotCount++;
            if(literal[i] == 'f')
                countF++;
        }
        if (dotCount > 1 || countF > 1)
        {
            std::cout << "char : impossible" << std::endl;
            std::cout << "int : impossible" << std::endl;
            std::cout << "float : impossible" << std::endl;
            std::cout << "double : impossible" << std::endl;
            return;
        }
        for (size_t i = 0; i < literal.length(); ++i)
        {
            if ((std::isalpha(literal[i]) && (literal.length() != i && literal[i] != 'f'))
                || (literal[i] == 'f' && literal[i + 1] != '\0'))
            {
                std::cout << "char : impossible" << std::endl;
                std::cout << "int : impossible" << std::endl;
                std::cout << "float : impossible" << std::endl;
                std::cout << "double : impossible" << std::endl;
                return;
            }
        }
    }

    // INT
    try
    {
        char *end;
        long resultInt = static_cast<int>(std::strtol(literal.c_str(), &end, 10));
        if (resultInt > INT_MAX || resultInt < INT_MIN)
        {
            std::cout << "int : impossible" << std::endl;
        }
        else
        {
            std::cout << "int : " << resultInt << std::endl;
        }
    }

    catch (std::exception &e)
    {
        std::cout << "int : impossible" << std::endl;
    }

    // CHAR
    try
    {
        resultChar = static_cast<char>(std::atoi(literal.c_str()));
        if (std::isprint(resultChar))
            std::cout << "char : '" << resultChar << "'" << std::endl;
        else
            std::cout << "char : Non displayable" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "char : impossible" << std::endl;
    }

    // FLOAT
    try
    {
        resultFloat = static_cast<float>(std::atof(literal.c_str()));
        std::cout << "float : " << resultFloat << ".0f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "float : impossible" << std::endl;
    }

    // DOUBLE
    try
    {
        resultDouble = static_cast<double>(std::atof(literal.c_str()));
        std::cout << "double : " << resultDouble << ".0" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "double : impossible" << std::endl;
    }
}
