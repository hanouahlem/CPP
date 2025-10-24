#pragma once 

#include <iostream>
#include <string>


template <typename T, typename f>

void iter(T *tab, int len, f function)
{
    if(!tab)
        return;
    for (int i = 0; i < len; i++)
    {
        function(tab[i]);
    }
}
