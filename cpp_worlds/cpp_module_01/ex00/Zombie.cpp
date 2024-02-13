#include "Zombie.hpp"

Zombie::Zombie(std::string name)
    :name(name)
{
}

Zombie::~Zombie()
{
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
