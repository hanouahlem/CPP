#include "Base.hpp"
#include "classABC.hpp"
#include <cstdlib> 
#include <ctime>

Base::~Base()
{
    // std::cout << "Destructor Base has called" << std::endl;

}

Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "The type of the ptr is : A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "The type is of the ptr: B" << std::endl;
    else if(dynamic_cast<C*>(p))
    std::cout << "The type is of the ptr : C" << std::endl;
}
void identify(Base& p) {
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The type of ref is : A" << std::endl;
        return;
    } 
    catch (std::exception& e)
    {

    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The type of ref is : B" << std::endl;
        return;
    } 
    catch (std::exception& e)
    {

    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The type of ref is : C" << std::endl;
        return;
    }
    catch (std::exception& e)
    {

    }
}