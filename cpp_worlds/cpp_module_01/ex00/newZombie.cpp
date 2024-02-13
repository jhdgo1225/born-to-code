#include "Zombie.hpp"
#include <cstdlib>

Zombie  *newZombie(std::string name)
{
    try
    {
        Zombie  *zombie = new Zombie(name);
        return (zombie);
    }
    catch (std::bad_alloc &exception)
    {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
}
