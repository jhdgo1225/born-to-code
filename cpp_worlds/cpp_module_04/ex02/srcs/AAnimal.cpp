#include "AAnimal.hpp"

AAnimal::AAnimal()
    :type("AAnimal")
{
    std::cout << "\033[1;32m" << "<< AAnimal Class is Created >>" << "\033[0m" << '\n';
}

AAnimal::AAnimal(const std::string type)
    :type(type)
{
    std::cout << "\033[1;32m" << "<< AAnimal Class is Created >>" << "\033[0m" << '\n';
}

AAnimal::~AAnimal()
{
    std::cout << "\033[1;31m" << "<< AAnimal Class is Destroyed >>" << "\033[0m" << '\n';
}

AAnimal::AAnimal(const AAnimal& rhs)
    :type(rhs.type)
{
    std::cout << "\033[1;32m"<< "<< AAnimal Class is Created >>" << "\033[0m" << '\n';
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    type = rhs.type;
    return *this;
}
