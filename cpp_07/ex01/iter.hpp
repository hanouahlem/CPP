#pragma once 

#include <iostream>
#include <string>


template <typename T, typename M>

void iter(T *tab, int len, M *cmd)
{
    for (int i = 0; i < len; i++)
    {
        cmd(tab[i]);
    }
}
