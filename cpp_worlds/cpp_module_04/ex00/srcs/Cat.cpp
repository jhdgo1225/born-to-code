#include "Cat.hpp"

Cat::Cat()
    :Animal("Cat")
{
    std::cout << "\033[1;32m" << "<< Cat Class is Created >>" << "\033[0m" << '\n';
}

Cat::~Cat()
{
    std::cout << "\033[1;31m" << "<< Cat Class is Destroyed >>" << "\033[0m" << '\n';
}

Cat::Cat(const Cat& rhs)
    :Animal(rhs.type)
{
    std::cout << "\033[1;32m" << "<< Cat Class is Created >>" << "\033[0m" << '\n';
}

Cat& Cat::operator=(const Cat& rhs)
{
    type = rhs.type;
    return *this;
}

void    Cat::makeSound()
{
    std::cout << "Cat " << type  << " Meow~~ 🐱" << '\n';
}
