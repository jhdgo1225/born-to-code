#include "Zombie.hpp"

int main(void)
{
    int cnt = 10;
    Zombie  *zombies = zombieHorde(cnt, "good");
    for (int i=0; i<cnt; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}
