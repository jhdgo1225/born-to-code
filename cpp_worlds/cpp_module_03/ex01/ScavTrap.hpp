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
    void    attack(const std::string target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    setAttackDamage(int damage);
    void    guardGate();
};

#endif
