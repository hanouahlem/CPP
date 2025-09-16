#include "Serialize.hpp"

Serialize::Serialize()
{
// std::cout << "Constructor Serialize has called" << std::endl;
}
Serialize::~Serialize()
{
    // std::cout << "Destructor Serialize has called" << std::endl;

}
Serialize::Serialize(Serialize const &other)
{
    (void)other;
}
Serialize &Serialize::operator=(const Serialize &other)
{
    (void)other;
    return(*this);
}

uintptr_t Serialize::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serialize::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}