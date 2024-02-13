#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "create Zombie!\n";
}

Zombie::~Zombie()
{
    std::cout << "delete Zombie\n";
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
