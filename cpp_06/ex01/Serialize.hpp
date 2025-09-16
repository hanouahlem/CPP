#pragma once

#include <stdint.h>
#include <iostream>

struct Data
{
    int number;
    std::string name;
};

class Serialize
{
    private :
            Serialize();
            ~Serialize();
            Serialize(Serialize const &other);
            Serialize &operator=(const Serialize &other);
    public :
           static uintptr_t serialize(Data* ptr);
           static Data* deserialize(uintptr_t raw);
};
