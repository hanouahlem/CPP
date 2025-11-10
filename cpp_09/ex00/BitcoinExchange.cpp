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

bool isValidDate(const std::string& date) {
    struct tm tm;
    return strptime(date.c_str(), "%Y-%m-%d", &tm) != NULL;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file '" << filename << "'." << std::endl;
        return false;
    }

    std::string dataLine;
    bool anyLoad = false;
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

        if (!isValidDate(date))
        {
            std::cerr << "Error: Invalid date format => " << date << std::endl;
            return false;
        }
        std::string skipSpaces;
        for (std::size_t i = 0; i < date.size(); ++i)
        {
            unsigned char c = static_cast<unsigned char>(date[i]);
            if (!std::isspace(c))
                skipSpaces += date[i];
        }
        date = skipSpaces;
        if (date.empty())
            continue;
        float rate = std::atof(rateStr.c_str());
        _rates[date] = rate;
        anyLoad = true;
        // std::cout << date << " | " << _rates[date] << std::endl;
    }
    if (!anyLoad) 
    {
        std::cout << "Error: no valid data loaded from " << filename << std::endl;
        return false;
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

    
    // parsing et valider de 'date' et 'value'
    if (_rates.empty()) 
    { 
        std::cout << "Erreur : empty line " << std::endl; 
        return; 
    }

    std::string date;
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t pos = line.find(" | ");
		if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string excRates = line.substr(pos + 3);
		double value = atof(excRates.c_str());
		
        if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

        std::map<std::string,float>::const_iterator mapIter = _rates.find(date);
        if (mapIter == _rates.end())
        {
            mapIter = _rates.upper_bound(date);
            if (mapIter == _rates.begin()) 
            {
                std::cout << "Error: no exchange rate available for date " << date << std::endl;
                continue;
            }
            --mapIter;
        }
        float rate = mapIter->second;
        float result = value * rate;
        std::cout << date << " => " << value << " = " << result << '\n';
    }
    file.close();
}

