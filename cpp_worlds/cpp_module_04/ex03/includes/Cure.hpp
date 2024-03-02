#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	std::string const& getType() const;
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
protected:
	std::string const type;
private:
	Cure(const Cure& rhs);
	Cure& operator=(const Cure& rhs);
};

#endif
