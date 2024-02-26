#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
public:
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(const ClapTrap& obj);
    ClapTrap& operator=(const ClapTrap& obj);
    virtual void    attack(const std::string target);
    virtual void    takeDamage(unsigned int amount);
    virtual void    beRepaired(unsigned int amount);
    virtual void    setAttackDamage(int damage);
    int             getAttackDamage();
    std::string&    getName();

protected:
    std::string     name;
    int             hitPoint;
    int             energyPoint;
    int             attackDamage;
};

#endif
