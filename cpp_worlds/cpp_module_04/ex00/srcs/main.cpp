#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal *animal = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Cat();
    std::cout << '\n';

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    std::cout << '\n';

    WrongAnimal *wrong = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();
    std::cout << '\n';

    wrong->makeSound();
    wrongCat->makeSound();

    std::cout << '\n';
    delete animal;
    delete dog;
    delete cat;
    return (0);
}
