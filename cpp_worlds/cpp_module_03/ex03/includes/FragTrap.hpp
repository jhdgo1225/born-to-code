#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap& obj);
    FragTrap& operator=(const FragTrap& obj);
    void    highFivesGuys(void);
protected:
    static const int fragTrapHitPoints;
    static const int fragTrapAttackDamage;
};

#endif
