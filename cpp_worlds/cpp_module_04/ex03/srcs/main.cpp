#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int	main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	std::cout << "\033[1;32m" << "[ 'Constructor', 'Equip' Test ]" << "\033[0m" << '\n';
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << '\n';

	std::cout << "\033[1;32m" << "[ 'Copy Constructor' Test ]" << "\033[0m" << '\n';
	ICharacter *bob = new Character("bob");
	ICharacter *copy = new Character(*(Character *)me);
	copy->use(0, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << '\n';

	std::cout << "\033[1;32m" << "[ More 'Equip', 'Unequip', 'Use' Function Test ]" << "\033[0m" << '\n';
	me->unequip(1);
	me->unequip(1);
	me->use(1, *bob);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(1, *bob);
	me->unequip(1);
	me->use(2, *bob);
	std::cout << '\n';

	std::cout << "\033[1;32m" << "[ 'Copy Assignment Operator' Test ]" << "\033[0m" << '\n';
	*(Character *)copy = *(Character *)me;
	copy->use(1, *bob);
	me->use(1, *bob);
	tmp = src->createMateria("cure");
	copy->equip(tmp);
	copy->use(1, *bob);
	me->use(1, *bob);
	std::cout << '\n';

	delete copy;
	delete bob;
	delete me;
	delete src;
	return (0);
}
