#include "ScalarConverter.hpp"

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
    return(*this);
}

void ScalarConverter::convert(std::string literal)
{
    int resultInt = 0;
    float resultFloat = 0;
    double resultDouble = 0;
    char resultChar = 0;

    if (literal.empty())
    {
        std::cout << "Error: Empty string" << std::endl;
        return;
    }
    for(int i = 0; (size_t)i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]) && !std::isdigit(literal[i + 1]) && literal[i] != '.' && literal[i] != 'f')
		{
            std::cout << "int : impossible" << std::endl;
            std::cout << "char : impossible" << std::endl;
            if (literal == "nan" || literal == "nanf")
 				std::cout << "float : nanf" << std::endl;
 			else if (literal == "-inf" || literal == "+inf"
 				|| literal == "-inff" || literal == "+inff")
 				std::cout << "float : " << literal[0] << "inff" << std::endl;
            else
 				std::cout << "float : impossible" << std::endl;

            if (literal == "nan" || literal == "nanf")
                std::cout << "double : nan" << std::endl;
            else if(literal == "-inf" || literal == "+inf"
 				|| literal == "-inff" || literal == "+inff")
             	std::cout << "double : " << literal[0] << "inf" << std::endl;
            else
 				std::cout << "double : impossible" << std::endl;
            return;
        }
    }

    // INT
    try
    {
        resultInt = std::atoi(literal.c_str());
        std::cout << "int : " << resultInt << std::endl;
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
            resultFloat = std::atof(literal.c_str());
            std::cout << "float : " << resultFloat << "f" << std::endl;
        } 
        catch (std::exception &e) 
        {
            std::cout << "float : impossible" << std::endl;
        }

        // DOUBLE
        try 
        {
            resultDouble = std::atof(literal.c_str());
            std::cout << "double : " << resultDouble << std::endl;
        } 
        catch (std::exception &e)
        {
                std::cout << "double : impossible" << std::endl;
        }
}
