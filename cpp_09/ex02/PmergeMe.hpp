#pragma once
  
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib> 
#include <climits>  
#include <cctype>    
#include <algorithm>
class PmergeMe
{
    private :
                std::vector<int> _vector;
                std::deque<int> _deque;
    public :
            int parseInput(int ac, char **av);
            int checkInt(long resConvert);
            int isValidNumber(const std::string &str);
            int pushIfGood(double resConvert);
            void printNumber();
};
