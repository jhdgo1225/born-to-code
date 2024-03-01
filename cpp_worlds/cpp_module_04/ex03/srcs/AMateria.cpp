#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
	:type(type)
{
	std::cout << "\033[1;32m" << "<< AMateria Class is Created >>" << "\033[0m" << '\n';
}

AMateria::~AMateria()
{
    std::cout << "\033[1;31m" << "<< AMateria Class is Destroyed >>" << "\033[0m" << '\n';
}

std::string const& AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " used a some materia." << '\n';
}
