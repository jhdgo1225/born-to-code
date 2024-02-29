#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // AAnimal *animal = new AAnimal();  // Not Instantiable
    AAnimal *testDog = new Dog();
    AAnimal *testCat = new Cat();

    // delete animal;
    delete testDog;
    delete testCat;
   
    Cat *cat = new Cat();
    std::cout << '\n';

    cat->addIdeas("hihi");
    cat->addIdeas("hehehe");
    cat->showIdeas();

    Cat *copyCat = new Cat(*cat);
    std::cout << '\n';

    copyCat->showIdeas();
    copyCat->addIdeas("Churue");
    copyCat->addIdeas("juseyo");
    cat->showIdeas();
    copyCat->showIdeas();

    *cat = *copyCat;
    cat->addIdeas("Churue");
    cat->showIdeas();
    copyCat->showIdeas();

    Dog *dog = new Dog();
    std::cout << '\n';

    dog->addIdeas("Dog");
    dog->addIdeas("Gum");
    dog->addIdeas("Juseyong!!");
    dog->showIdeas();
    Dog *copyDog = new Dog(*dog);
    copyDog->addIdeas("Wang Wang 🐶");
    copyDog->showIdeas();
    *dog = *copyDog;
    dog->showIdeas();

    delete cat;
    delete copyCat;
    delete dog;
    delete copyDog;
    return (0);
}
