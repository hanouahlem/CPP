#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}


bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
    {
		std::cout << "Error: could not open file." << std::endl;
		return(-1);
	}

}

void BitcoinExchange::processInput(const std::string& filename) const
{
	
}