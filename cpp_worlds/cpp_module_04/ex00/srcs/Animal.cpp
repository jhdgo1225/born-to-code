#include "Animal.hpp"

Animal::Animal()
    :type("Animal")
{
    std::cout << "\033[1;32m" << "<< Animal Class is Created >>" << "\033[0m" << '\n';
}

Animal::Animal(const std::string type)
    :type(type)
{
    std::cout << "\033[1;32m" << "<< Animal Class is Created >>" << "\033[0m" << '\n';
}

Animal::~Animal()
{
    std::cout << "\033[1;31m" << "<< Animal Class is Destroyed >>" << "\033[0m" << '\n';
}

Animal::Animal(const Animal& rhs)
    :type(rhs.type)
{
    std::cout << "\033[1;32m"<< "<< Animal Class is Created >>" << "\033[0m" << '\n';
}

Animal& Animal::operator=(const Animal& rhs)
{
    type = rhs.type;
    return *this;
}

void    Animal::makeSound()
{
    std::cout << "Normal Animal " << type << " Sound is nothing..." << '\n';
}
