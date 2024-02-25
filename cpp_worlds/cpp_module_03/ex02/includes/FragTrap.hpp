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
    void    attack(const std::string target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    setAttackDamage(int damage);
    void    highFivesGuys(void);
};

#endif
