#include "Ice.hpp"
#include <cstdlib>

Ice::Ice()
	:AMateria("ice")
{
}

Ice::~Ice()
{
}

std::string const& Ice::getType() const
{
	return (type);
}

AMateria* Ice::clone() const
{
	try
	{
		return (new Ice());
	}
	catch (std::bad_alloc& exception)
	{
		std::cout << "exception : " << exception.what() << '\n';
        std::abort();
	}
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n';
}
