#include "PmergeMe.hpp"


int isValidNumber(const std::string &str)
{
    if (str.empty())
        return 1;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i])) 
            return 1;
    }
    return 0;
}


int PmergeMe::parseInput(int ac, char **av)
{
    int i = 0;
    std::string str;
    str = av[i];
    while()
    {
        isValidNumber(str);

    }
}