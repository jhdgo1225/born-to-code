#include "Character.hpp"
#include <cstdlib>

Character::Character(const std::string name)
	:name(name)
{
	try
	{
		collector = new UnusedMateriaCollector();
		for (int i=0; i<4; i++)
			slots[i] = NULL;
	}
	catch (std::bad_alloc& exception)
	{
		std::cout << "exception : " << exception.what() << '\n';
        std::abort();
	}
}

Character::~Character()
{
	collector->deleteAll();
	delete collector;
	for (int i=0; i<4; i++)
	{
		if (slots[i] != NULL)
		{
			delete slots[i];
			slots[i] = NULL;
		}
	}
}

Character::Character(const Character& rhs)
    :ICharacter(),
	 name(rhs.name)
{
	for (int i=0; i<4; i++)
	{
		if (!rhs.slots[i])
			slots[i] = NULL;
		else
			slots[i] = rhs.slots[i]->clone();
	}
	collector = new UnusedMateriaCollector();
	*collector = *rhs.collector;
}

Character& Character::operator=(const Character& rhs)
{
	name = rhs.name;
	for (int i=0; i<4; i++)
	{
		if (slots[i])
			delete slots[i];
		if (!rhs.slots[i])
			slots[i] = NULL;
		else
			slots[i] = rhs.slots[i]->clone();
	}
	collector = rhs.collector;
	return *this;
}

std::string const& Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "! Incorrect Behavior !" << '\n';
		return ;
	}
	for (int i=0; i<4; i++)
	{
		if (!slots[i])
		{
			std::cout << m->getType() << " is equiped in a " << i << " slot." << '\n';
			slots[i] = m;
			m = NULL;
			return ;
		}
	}
	std::cout << name << "'s Materia slots is full." << '\n';
}

void	Character::unequip(int idx)
{
	if (!slots[idx])
	{
		std::cout << idx << " slot is empty..." << '\n';
		return ;
	}
	std::cout << name << " unequiped " << slots[idx]->getType() << " in a " << idx << " slot." << '\n';
	collector->push(slots[idx]);
	slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (!slots[idx])
	{
		std::cout << idx << " slot is empty..." << '\n';
		return ;
	}
	slots[idx]->use(target);
}
