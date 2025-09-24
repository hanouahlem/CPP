#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	std::string str;
	if (ac != 2)
	{
		std::cerr << "Wrong arguments, please make one" << std::endl;
		return (1);
	}
	str = av[1];
	ScalarConverter::convert(str);
	return (0);
}