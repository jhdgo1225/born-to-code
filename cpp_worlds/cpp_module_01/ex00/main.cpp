#include "Zombie.hpp"
#include <cstdlib>

int main()
{
    std::cout << "\033[1;32m" << "Create a Zombie in Stack\n" << "\033[0m";
    Zombie stackZombie("amy");
    stackZombie.announce();

    std::cout << "\033[1;33m" << "\nCreate a Zombie in Heap\n" << "\033[0m";
    try
    {
        Zombie  *heapZombie = new Zombie("hip");
        heapZombie->announce();
        delete heapZombie;
    }
    catch (std::bad_alloc &exception)
    {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }

    std::cout << "\033[1;34m" << "\nExecute randomChump function\n" << "\033[0m";
    randomChump("omnic");

    std::cout << "\033[1;35m" << "\nExecute randomChump function\n" << "\033[0m";
    Zombie  *newThing = newZombie("jomho");
    newThing->announce();
    delete newThing;

    return (0);
}
