#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main() 
{
    const int N = 10;
    Animal* animals[N];

    // Remplir le tableau
    for (int i = 0; i < N / 2; ++i)
    {
        animals[i] = new Dog();
        animals[i]->makeSound();
    }
    for (int i = N / 2; i < N; ++i)
    {
        animals[i] = new Cat();
        animals[i]->makeSound();
    }

    // Supprimer les animaux
    for (int i = 0; i < N; ++i)
        delete animals[i];

    return 0;
}

