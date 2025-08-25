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
		if (!std::isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
		{
            std::cout << "int: impossible" << std::endl;
            std::cout << "char : impossible" << std::endl;
            if (literal == "nan" || literal == "nanf")
 				std::cout << "float: nanf" << std::endl;
 			else if (literal == "-inf" || literal == "+inf"
 				|| literal == "-inff" || literal == "+inff")
 				std::cout << "float: " << literal[0] << "inff" << std::endl;
            else
 				std::cout << "float: impossible" << std::endl;

            if (literal == "nan" || literal == "nanf")
                std::cout << "double: nan" << std::endl;
            else if(literal == "-inf" || literal == "+inf"
 				|| literal == "-inff" || literal == "+inff")
             	std::cout << "double: " << literal[0] << "inf" << std::endl;
            else
 				std::cout << "double: impossible" << std::endl;
            return;
        }
        // convert int
        try
        {
            resultInt = static_cast<char>
        }
        catch(const std::exception& e)
        {
            std::cout << "" << std::endl;
        }
        


    }
    

}















// void ScalarConverter::convert(std::string literal)
// {
//     std::string str = "42";
//     try
//     {
//         int value = std::stoi(str);
//         std::cout << "int: " << value << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "int: impossible" << std::endl;
//     }




//     std::string str = "4.2f";
//     try
//     {
//         if (str.back() == 'f')
//             str.pop_back(); // Enlève le 'f'
//         float value = std::stof(str);
//         std::cout << "float: " << value << "f" << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "float: impossible" << std::endl;
//     }

//     std::string str = "4.2";
//     try
//     {
//         double value = std::stod(str);
//         std::cout << "double: " << value << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "double: impossible" << std::endl;
//     }

//     std::string str = "'a'";
//     if (str.length() == 3 && str.front() == '\'' && str.back() == '\'')
//     {
//         char value = str[1];
//         if (isprint(value))
//             std::cout << "char: '" << value << "'" << std::endl;
//         else
//             std::cout << "char: Non displayable" << std::endl;
//     }
//     else
//     {
//         std::cout << "char: impossible" << std::endl;
//     }

//     std::string str = "nanf";
//     if (str == "nanf" || str == "nan")
//     {
//         std::cout << "float: nanf" << std::endl;
//         std::cout << "double: nan" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "char: impossible" << std::endl;
//     }
// }