#include "FragTrap.hpp"

const int FragTrap::fragTrapHitPoints = 100;
const int FragTrap::fragTrapAttackDamage = 30;
FragTrap::FragTrap(std::string name)
    :ClapTrap(name)
{
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
    std::cout << "<< FragTrap " << name << " is Created!! >>" << '\n';
}

FragTrap::~FragTrap()
{
    std::cout << "<< FragTrap " << name << " is Destroyed!! >>" << '\n';
}

FragTrap::FragTrap(const FragTrap& obj)
    :ClapTrap(obj.name)
{
    std::cout << "<< FragTrap " << name << " is Created!! >>" << '\n';
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    name = obj.name;
    hitPoint = obj.hitPoint;
    attackDamage = obj.attackDamage;
    energyPoint = obj.energyPoint;
    return *this;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " highFives!" << '\n';
    std::cout << '\n';
}
