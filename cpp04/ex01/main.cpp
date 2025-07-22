#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const int N = 10;
    Animal *animals[N];

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
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "\n=== Test constructeur de copie ===\n";
    Dog originalDog;
    Dog copyDog(originalDog);

    std::cout << "\n=== Test opérateur d'assignation ===\n";
    Cat originalCat;
    Cat assignedCat;
    assignedCat = originalCat;
    
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < N; ++i)
        delete animals[i];

    return 0;
}


