#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: please make more number" << std::endl;
        return(1);
    }
    RPN stack;
    stack.calculator(av[1]);
 
    return(0);
    
}