#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private :
            std::map<std::string, float> _rates;
    public :
            BitcoinExchange();
            ~BitcoinExchange();
            bool loadDatabase(const std::string& filename);
            void processInput(const std::string& filename) const;
};