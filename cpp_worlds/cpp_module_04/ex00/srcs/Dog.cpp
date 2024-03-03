#include "Dog.hpp"

Dog::Dog()
    :Animal("Dog")
{
    std::cout << "\033[1;32m" << "<< Dog Class is Created >>" << "\033[0m" << '\n';
}

Dog::~Dog()
{
    std::cout << "\033[1;31m" << "<< Dog Class is Destroyed >>" << "\033[0m" << '\n';
}

Dog::Dog(const Dog& rhs)
    :Animal(rhs.type)
{
    std::cout << "\033[1;32m" << "<< Dog Class is Created >>" << "\033[0m" << '\n';
}

Dog& Dog::operator=(const Dog& rhs)
{
    type = rhs.type;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Dog " << type << " Meong!Meong! 🐶" << '\n';
}
