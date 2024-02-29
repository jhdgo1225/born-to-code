#include "WrongCat.hpp"

WrongCat::WrongCat()
    :WrongAnimal("Cat")
{
    std::cout << "\033[1;32m" << "<< WrongCat Class is Created >>" << "\033[0m" << '\n';
}

WrongCat::~WrongCat()
{
    std::cout << "\033[1;31m" << "<< WrongCat Class is Destroyed >>" << "\033[0m" << '\n';
}

WrongCat::WrongCat(const WrongCat& rhs)
    :WrongAnimal(rhs.type)
{
    std::cout << "\033[1;32m" << "<< WrongCat Class is Created >>" << "\033[0m" << '\n';
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    type = rhs.type;
    return *this;
}

void    WrongCat::makeSound()
{
    std::cout << "Cat " << type  << " Meow~~ 🐱" << '\n';
}
