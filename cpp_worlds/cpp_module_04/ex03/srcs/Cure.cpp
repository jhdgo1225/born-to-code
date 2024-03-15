#include "Cure.hpp"
#include <cstdlib>

Cure::Cure()
	:AMateria("cure")
{
}

Cure::~Cure()
{
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
