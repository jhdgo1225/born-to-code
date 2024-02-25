#include "FragTrap.hpp"

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

void    FragTrap::attack(const std::string target)
{
    std::cout << "\033[1;35m" << "[FragTrap " << name << "'s Attack Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "FragTrap " << name << " was dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    if (hitPoint > 0 && energyPoint > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << '\n';
        energyPoint -= 1;
        std::cout << '\n';
        return ;
    }
    std::cout << "FragTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

void    FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "\033[1;31m" << "[FragTrap " << name << "'s take Damage Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "FragTrap " << name << " was already dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    int tmp = hitPoint - (int)amount;
    if (tmp < 0 || tmp > hitPoint)
        hitPoint = 0;
    else
        hitPoint = tmp;
    std::cout << "FragTrap " << name << " takes " << amount << " points damage." << '\n';
    std::cout << name << " has now " << hitPoint << " points." << '\n';
    std::cout << '\n';
}

void    FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "\033[1;32m" << "[FragTrap " << name << "'s Be Repaired Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "FragTrap " << name << " was dead..." << '\n';
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
        std::cout << "FragTrap " << name << " be repaired " << amount << " points." << '\n';
        std::cout << name << " has now " << hitPoint << " points." << '\n';
        std::cout << '\n';
        return ;
    }
    std::cout << "FragTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

void    FragTrap::setAttackDamage(int damage)
{
    std::cout << "\033[1;36m" << "[FragTrap " << name << "'s Set Attack Damage Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "FragTrap " << name << " was dead..." << '\n';
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
    std::cout << "FragTrap " << name << " gets " << damage << " attack damage stat." << '\n';
    std::cout << '\n';
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " highFives!" << '\n';
    std::cout << '\n';
}
