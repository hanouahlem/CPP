#include "Base.hpp"
#include "classABC.hpp"
#include <cstdlib> 
#include <ctime>     



int main()
{
    // std::srand(static_cast<unsigned int>(std::time(0)));
    Base *ptr;
    
    ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete(ptr);
}