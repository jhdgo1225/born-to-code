#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap& obj);
    FragTrap& operator=(const FragTrap& obj);
    virtual void    attack(const std::string target);
    virtual void    takeDamage(unsigned int amount);
    virtual void    beRepaired(unsigned int amount);
    virtual void    setAttackDamage(int damage);
    void    highFivesGuys(void);
};

#endif
