#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    :type("Animal")
{
    std::cout << "\033[1;32m" << "<< WrongAnimal Class is Created >>" << "\033[0m" << '\n';
}

WrongAnimal::WrongAnimal(const std::string type)
    :type(type)
{
    std::cout << "\033[1;32m" << "<< WrongAnimal Class is Created >>" << "\033[0m" << '\n';
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[1;31m" << "<< WrongAnimal Class is Destroyed >>" << "\033[0m" << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
    :type(rhs.type)
{
    std::cout << "\033[1;32m"<< "<< WrongAnimal Class is Created >>" << "\033[0m" << '\n';
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    type = rhs.type;
    return *this;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Animal " << type << " Sound is nothing..." << '\n';
}
