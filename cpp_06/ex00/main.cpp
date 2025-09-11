#include "ScalarConverter.hpp"
#include <limits>

int main(int ac, char **av)
{
	std::string str;
	if (ac != 2)
	{
		std::cerr << "Wrong arguments, please" << std::endl;
		return (1);
	}
	str = av[1];
	std::cout << std::fixed << std::setprecision(4);
	ScalarConverter::convert(str);
	return (0);
}