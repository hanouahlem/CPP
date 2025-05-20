
#include <iostream>

int main(int ac, char **av)
{
    int i = 1;
    int j;
    if(ac > 1)
    {
        while(av[i])
        {
            j = 0;
            while(av[i][j])
            {
                std::cout << (char)std::toupper(av[i][j]);
                j++;
            }
            i++;
        }
        return(0);
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    return(0);
}
