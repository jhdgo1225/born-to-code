#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    :name(name),
     hitPoint(10),
     energyPoint(10),
     attackDamage(0)
{
    std::cout << "<< ClapTrap " << name << " is Created!! >>" << '\n';
}

ClapTrap::~ClapTrap()
{
    std::cout << "<< ClapTrap " << name << " is Destroyed!! >>" << '\n';
}

ClapTrap::ClapTrap(const ClapTrap& obj)
    :name(obj.name)
{
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    name = obj.name;
    hitPoint = obj.hitPoint;
    energyPoint = obj.energyPoint;
    attackDamage = obj.attackDamage;
    return *this;
}

void    ClapTrap::attack(const std::string target)
{
    std::cout << "\033[1;35m" << "[ClapTrap " << name << "'s Attack Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " was dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    if (hitPoint > 0 && energyPoint > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << '\n';
        energyPoint -= 1;
        std::cout << '\n';
        return ;
    }
    std::cout << "ClapTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "\033[1;31m" << "[ClapTrap " << name << "'s take Damage Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " was already dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    int tmp = hitPoint - (int)amount;
    if (tmp < 0 || tmp > hitPoint)
        hitPoint = 0;
    else
        hitPoint = tmp;
    std::cout << "ClapTrap " << name << " takes " << amount << " points damage." << '\n';
    std::cout << name << " has now " << hitPoint << " points." << '\n';
    std::cout << '\n';
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "\033[1;32m" << "[ClapTrap " << name << "'s Be Repaired Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " was dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    if (hitPoint > 0 && energyPoint > 0)
    {
        if (hitPoint + (int)amount < hitPoint)
            hitPoint = 2147483647;
        else
            hitPoint += amount;
        energyPoint -= 1;
        std::cout << "ClapTrap " << name << " be repaired " << amount << " points." << '\n';
        std::cout << name << " has now " << hitPoint << " points." << '\n';
        std::cout << '\n';
        return ;
    }
    std::cout << "ClapTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

int ClapTrap::getAttackDamage()
{
    return (attackDamage);
}

void    ClapTrap::setAttackDamage(int damage)
{
    std::cout << "\033[1;36m" << "[ClapTrap " << name << "'s Set Attack Damage Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " was dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    if (damage <= 0)
    {
        std::cout << "Don't give minus or zero attack damage points!" << '\n';
        std::cout << '\n';
        return ;
    }
    attackDamage = damage;
    std::cout << "ClapTrap " << name << " gets " << damage << " attack damage stat." << '\n';
    std::cout << '\n';
}
