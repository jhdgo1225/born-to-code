#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i=0; i<4; i++)
		slots[i] = NULL;
	std::cout << "\033[1;32m" << "<< MateriaSource Class is Created >>" << "\033[0m" << '\n';
}

MateriaSource::~MateriaSource()
{
	for (int i=0; i<4; i++)
	{
		if (slots[i] != NULL)
		{
			delete slots[i];
			slots[i] = NULL;
		}
	}
	std::cout << "\033[1;31m" << "<< MateriaSource Class is Destroyed >>" << "\033[0m" << '\n';
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Unexpected Behavior..." << '\n';
		return ;
	}
	for (int i=0; i<4; i++)
	{
		if (!slots[i])
		{
			slots[i] = m->clone();
			delete m;
			m = NULL;
			return ;
		}
	}
	std::cout << "MateriaSource is full." << '\n';
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i=0; i<4; i++)
	{
		if (slots[i] != NULL)
		{
			if (!type.compare(slots[i]->getType()))
				return (slots[i]->clone());
		}
	}
	return (NULL);
}
