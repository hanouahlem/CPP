#pragma once
  
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <climits>  
#include <cctype>    
#include <set>


class PmergeMe
{
    private :
            std::vector<int> numbers;
    public :
            int parseInput(int ac, char **av);
};
