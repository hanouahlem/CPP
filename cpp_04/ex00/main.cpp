#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    j->makeSound(); //will output the Dog sound!
    i->makeSound(); //will output the Cat sound!
    meta->makeSound();
   
    std::cout << std::endl;
    std::cout << std::endl;
    
    //Wrong class
    WrongAnimal* animal = new WrongAnimal();
    WrongAnimal* cat = new WrongCat();

    animal->makeSound(); // Affiche "WrongAnimal sound"
    cat->makeSound();    // Affiche aussi "WrongAnimal sound" car pas de virtual !
    
    delete animal;
    delete cat;
    delete meta;
    delete i;
    delete j;

    return 0;
}
