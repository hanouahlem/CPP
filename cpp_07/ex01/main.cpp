#include "iter.hpp"

void print_char(int a)
{
    std::cout << a << std::endl;
}

void print_str(std::string a)
{
    std::cout << a << std::endl;
}
void print_float(float a)
{
    std::cout << a << std::endl;
}

int main()
{
    int tab[3] = {10, 15, 22};
    std::string str[3] = {"un", "deux", "trois"};
    float flt[3] = {10.25, 15.15, 22.22};

    std::cout << "mon tableau de int :" << std::endl;
    iter(tab, 3, print_char);
    std::cout << "mon tableau de string :" << std::endl;
    iter(str, 3, print_str);
    std::cout << "mon tableau de float :" << std::endl;
    iter(flt, 3, print_float);
    return 0;
}