#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : name(name),
      weaponB(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (!weaponB)
    {
        std::cout << name << " can't attack with no weapon!!\n";
        return ;
    }
    std::cout << name << " attacks with their " << weaponB->getType() << '\n';
}

void HumanB::setWeapon(Weapon& newWeapon)
{
    Weapon *old = weaponB;
    weaponB = &newWeapon;
    delete old;
}
