#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const int N = 10;
    Animal *animals[N];

    // Création des animaux (moitié Dog, moitié Cat)
    for (int i = 0; i < N / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (int i = N / 2; i < N; ++i)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n--- TEST DES SONS ---" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        animals[i]->makeSound();
    }

    std::cout << "\n--- TEST DE COPIE PROFONDE ---" << std::endl;
    Dog basicDog;
    {
        Dog copyDog = basicDog; // appel du constructeur de copie
    } // Fin de vie de copyDog, destructeur appelé

    std::cout << "\n--- DESTRUCTION DES ANIMAUX ---" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        delete animals[i];
    }

    // TEST IMPOSSIBLE (Doit être commenté sinon ça ne compile pas)
    // Animal a; // Interdit : classe abstraite
    // Animal* a = new Animal(); // Interdit : classe abstraite

    return 0;
}
