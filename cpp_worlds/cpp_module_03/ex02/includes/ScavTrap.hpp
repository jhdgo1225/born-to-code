#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(const ScavTrap& obj);
    ScavTrap& operator=(const ScavTrap& obj);
    virtual void    attack(const std::string target);
    virtual void    takeDamage(unsigned int amount);
    virtual void    beRepaired(unsigned int amount);
    virtual void    setAttackDamage(int damage);
    void            guardGate();
};

#endif
