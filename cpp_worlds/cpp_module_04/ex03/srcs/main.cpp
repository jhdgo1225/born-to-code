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

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	ICharacter *copy = new Character(*(Character *)me);
	copy->use(0, *bob);
	ICharacter *copy2 = me;
	copy2->use(2, *copy);

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);
	me->unequip(1);
	me->use(1, *bob);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(1, *bob);
	me->unequip(1);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;
	return (0);
}
