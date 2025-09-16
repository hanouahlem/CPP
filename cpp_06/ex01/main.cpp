#include "Serialize.hpp"

int main() 
{
    Data data = {42, "hello"};
    uintptr_t raw = Serialize::serialize(&data);
    Data* ptr = Serialize::deserialize(raw);

    // Vérification
    if (ptr == &data)
        std::cout << "C'est le même pointeur, ça marche !" << std::endl;
    else
        std::cout << "Erreur de conversion !" << std::endl;
}