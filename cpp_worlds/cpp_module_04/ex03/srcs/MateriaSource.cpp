#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i=0; i<4; i++)
		slots[i] = NULL;
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
