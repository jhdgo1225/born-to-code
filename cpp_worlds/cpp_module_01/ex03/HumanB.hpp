#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class   HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& newWeapon);
private:
    std::string name;
    Weapon *weaponB;
};

#endif
