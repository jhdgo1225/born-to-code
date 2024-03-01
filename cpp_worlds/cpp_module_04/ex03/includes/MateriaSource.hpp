#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const& type);
private:
	MateriaSource(const MateriaSource& rhs);
	MateriaSource& operator=(const MateriaSource& rhs);
	AMateria *slots[4];
};

#endif
