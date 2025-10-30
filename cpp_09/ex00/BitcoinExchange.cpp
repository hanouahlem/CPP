#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange:: ~BitcoinExchange()
{}


bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file '" << filename << "'." << std::endl;
        return false;
    }
	
    std::cout << "Le fichier '" << filename << "' est ouvert avec succès dans loadDatabase." << std::endl;
    // Ici vous pouvez lire la DB si besoin.
    file.close();
    return true;
}

void BitcoinExchange::processInput(const std::string& filename) const
{
    // On utilise filename pour éviter l'erreur -Werror,-Wunused-parameter
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file '" << filename << "' dans processInput." << std::endl;
        return;
    }

    std::cout << "Le fichier '" << filename << "' est ouvert avec succès dans processInput." << std::endl;
    // Ici vous pouvez lire et tester l'input.
    file.close();
}