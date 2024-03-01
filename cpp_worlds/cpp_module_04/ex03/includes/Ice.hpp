#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	std::string const& getType() const;
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
protected:
	std::string const type;
private:
	Ice(const Ice& rhs);
	Ice& operator=(const Ice& rhs);
};

#endif
