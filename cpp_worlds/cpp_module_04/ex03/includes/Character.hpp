#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "UnusedMateriaCollector.hpp"

class Character : public ICharacter
{
public:
	Character(const std::string name);
	Character(const Character& rhs);
	Character& operator=(const Character& rhs);
	virtual ~Character();
	virtual std::string const& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
private:
	std::string name;
	AMateria *slots[4];
	UnusedMateriaCollector *collector;
};

#endif
