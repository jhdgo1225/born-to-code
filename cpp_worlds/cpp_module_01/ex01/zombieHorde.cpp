#include "Zombie.hpp"
#include <cstdlib>

Zombie  *zombieHorde(int N, std::string name)
{
    try
    {
        Zombie  *zombie = new Zombie[N];
        for (int i=0; i<N; i++)
        {
            zombie[i].setName(name);
        }
        return (zombie);
    }
    catch (std::bad_alloc &exception)
    {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
}
