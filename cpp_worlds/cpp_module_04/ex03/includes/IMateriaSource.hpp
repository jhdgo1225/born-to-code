#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP
# include "AMateria.hpp"

class IMateriaSource
{
public:
	IMateriaSource();
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const& type) = 0;
private:
	IMateriaSource(const IMateriaSource& rhs);
	IMateriaSource& operator=(const IMateriaSource& rhs);
};

#endif
