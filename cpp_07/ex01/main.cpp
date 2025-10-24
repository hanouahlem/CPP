#include "iter.hpp"

template <typename T>
void    print(T& c)
{
    std::cout << c << std::endl;
}

template <typename T>
void    print_const(const T& c)
{
    std::cout << c << std::endl;
}
int    main(void)
{
    std::string tab1[3] = { "Un ","deux", "trois"};
    std::cout << "mon tableau de string :" << std::endl;
    iter(tab1, 3, print<std::string>);

    int tab2[5] = {0, 1, 2, 3, 4};
    std::cout << "mon tableau de int :" << std::endl;
    iter(tab2, 5, print<int>);

    std::cout << std::endl;

    const std::string tab_const[4] = { "Quatre ","Cinq", "Six","sept"};
    std::cout << "mon tableau de string const:" << std::endl;
    iter(tab_const, 4, print_const<std::string>);

    const int tab_const2[5] = {5, 6, 7, 8, 9};
    std::cout << "mon tableau de int const:" << std::endl;
    iter(tab_const2, 5, print_const<int>);

    return 0;
}
