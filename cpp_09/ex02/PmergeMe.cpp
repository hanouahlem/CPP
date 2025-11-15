#include "PmergeMe.hpp"

void printfError(std::string error)
{
    std::cout << "Error" << error << std::endl;
}

void PmergeMe::printNumber()
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

    std::cout << "Deque:  ";
    for (size_t i = 0; i < _deque.size(); ++i)
        std::cout << _deque[i] << " ";
    std::cout << std::endl;
}

int PmergeMe::checkInt(long resConvert)
{
    if (resConvert < 0)
        return (printfError(" : no negative number"), 1);
    if (resConvert > INT_MAX)
        return (printfError(" : value too large "), 1);
    return (0);
}

int PmergeMe::isValidNumber(const std::string &str)
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
bool contains_in_vector(const std::vector<int>& v, int x)
{
    return std::find(v.begin(), v.end(), x) != v.end();
}

int PmergeMe::pushIfGood(double resConvert)
{
    if (contains_in_vector(_vector, resConvert )) 
    {
        std::cerr << "Error: duplicate value " << resConvert << std::endl;
        return 1;
    }
    _vector.push_back(static_cast<int>(resConvert));
    _deque.push_back(static_cast<int>(resConvert));
    return(0);
}


int PmergeMe::parseInput(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string str;
        str = av[i];
        if (isValidNumber(str))
            return (printfError(" : Invalid arguments"), 1);
        long resConvert;
        resConvert = std::strtol(av[i], NULL, 10);
        if (checkInt(resConvert))
            return (1);
        if(pushIfGood(resConvert))
            return (1);
    }
    printNumber();
    return (0);
}
