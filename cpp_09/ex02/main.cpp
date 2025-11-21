#include "PmergeMe.hpp"


int main(int ac, char **av)
{  
    if (ac < 2)
    {
        std::cerr << "Error: no numbers provided" << std::endl;
        return 1;
    }
    PmergeMe pm;
    if(pm.parseInput(ac, av))
        return 1;
    pm.myAlgo();
    return 0;
}

