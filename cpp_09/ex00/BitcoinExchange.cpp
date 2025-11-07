#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}
BitcoinExchange:: ~BitcoinExchange()
{

}

static std::string trim(const std::string& line) {
    std::size_t start = line.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) 
        return "";
    std::size_t end = line.find_last_not_of(" \t\r\n");
    return line.substr(start, end - start + 1);
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file '" << filename << "'." << std::endl;
        return false;
    }
    std::cout << "Le fichier '" << filename << "' est ouvert avec succès dans loadDatabase." << std::endl;
    
    std::string dataLine;
    while (std::getline(file, dataLine))
    {
        if (dataLine.empty())
            continue;
        std::size_t comma = dataLine.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = trim(dataLine.substr(0, comma));
        std::string rateStr = trim(dataLine.substr(comma + 1));
        if (date == "date" || rateStr == "exchange_rate")
            continue;

        std::string skipSpaces;
        for (std::size_t i = 0; i < date.size(); ++i)
        {
            unsigned char c = static_cast<unsigned char>(date[i]);
            if (!std::isspace(c))
                skipSpaces += date[i];
        }
        date = skipSpaces;
        float rate = std::atof(rateStr.c_str());
        _rates[date] = rate;
        std::cout << date << " | " << _rates[date] << std::endl;
    }
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
