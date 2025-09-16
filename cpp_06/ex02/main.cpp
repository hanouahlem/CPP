#include "Base.hpp"
#include <cstdlib>   // pour rand() et srand()
#include <ctime>     // pour time()


Base *generate(void)
{
    int random = std::rand() % 3; // 0, 1 ou 2

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
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
}
void identify(Base& p) {
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } 
    catch (std::bad_cast&) 
    {

    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
    catch (std::bad_cast&) 
    {

    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
     catch (std::bad_cast&) {}
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Base *p = generate();
    Base &ptr = generate();
}