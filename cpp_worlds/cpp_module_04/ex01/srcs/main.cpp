#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    Animal *animals[20];
    for (int i = 0; i < 20; i += 2)
    {
        std::cout << "========== count [" << i + 1 << "] ==========" << '\n';
        animals[i]= new Dog();
        animals[i + 1] = new Cat();
        std::cout << "================================" << '\n';
    }
    std::cout << '\n';

    for (int i = 0; i < 20; i++)
    {
        std::cout << "========== count [" << i + 1 << "] ==========" << '\n';
        delete animals[i];
        std::cout << "================================" << '\n';
    }
    std::cout << '\n';

    Cat *cat = new Cat();
    std::cout << '\n';
    cat->addIdeas("hihi");
    cat->addIdeas("hehehe");
    cat->showIdeas();

    Cat *copyCat = new Cat(*cat);
    std::cout << '\n';
    copyCat->showIdeas();
    copyCat->addIdeas("Bob");
    copyCat->addIdeas("juseyo");
    cat->showIdeas();
    copyCat->showIdeas();

    *cat = *copyCat;
    cat->addIdeas("Churue");
    cat->showIdeas();
    copyCat->showIdeas();

    Dog *dog = new Dog();
    std::cout << '\n';
    dog->addIdeas("Gae");
    dog->addIdeas("Gum");
    dog->addIdeas("Juseyo!");
    dog->showIdeas();
    Dog *copyDog = new Dog(*dog);
    copyDog->showIdeas();
    copyDog->addIdeas("Wang Wang 🐶");
    *dog = *copyDog;
    dog->showIdeas();

    delete cat;
    delete copyCat;
    delete dog;
    delete copyDog;
    return (0);
}
