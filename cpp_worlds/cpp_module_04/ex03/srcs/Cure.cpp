#include "Cure.hpp"
#include <cstdlib>

Cure::Cure()
	:AMateria("cure")
{
	std::cout << "\033[1;32m" << "<< Cure Class is Created >>" << "\033[0m" << '\n';
}

Cure::~Cure()
{
    std::cout << "\033[1;31m" << "<< Cure Class is Destroyed >>" << "\033[0m" << '\n';
}

std::string const& Cure::getType() const
{
	return (type);
}

AMateria* Cure::clone() const
{
	try
	{
		return (new Cure());
	}
	catch (std::bad_alloc& exception)
	{
		std::cout << "exception : " << exception.what() << '\n';
        std::abort();
	}
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << '\n';
}
