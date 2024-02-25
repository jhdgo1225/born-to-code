#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
    :ClapTrap(name)
{
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "<< ScavTrap " << name << " is Created!! >>" << '\n';
}

ScavTrap::~ScavTrap()
{
    std::cout << "<< ScavTrap " << name << " is Destroyed!! >>" << '\n';
}

ScavTrap::ScavTrap(const ScavTrap& obj)
    :ClapTrap(obj.name)
{
    std::cout << "<< ScavTrap " << name << " is Created!! >>" << '\n';
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    name = obj.name;
    hitPoint = obj.hitPoint;
    attackDamage = obj.attackDamage;
    energyPoint = obj.energyPoint;
    return *this;
}

void    ScavTrap::attack(const std::string target)
{
    std::cout << "\033[1;35m" << "[ScavTrap " << name << "'s Attack Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ScavTrap " << name << " was dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    if (hitPoint > 0 && energyPoint > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << '\n';
        energyPoint -= 1;
        std::cout << '\n';
        return ;
    }
    std::cout << "ScavTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "\033[1;31m" << "[ScavTrap " << name << "'s take Damage Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ScavTrap " << name << " was already dead..." << '\n';
        std::cout << '\n';
        return ;
    }
    int tmp = hitPoint - (int)amount;
    if (tmp < 0 || tmp > hitPoint)
        hitPoint = 0;
    else
        hitPoint = tmp;
    std::cout << "ScavTrap " << name << " takes " << amount << " points damage." << '\n';
    std::cout << name << " has now " << hitPoint << " points." << '\n';
    std::cout << '\n';
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "\033[1;32m" << "[ScavTrap " << name << "'s Be Repaired Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ScavTrap " << name << " was dead..." << '\n';
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
        std::cout << "ScavTrap " << name << " be repaired " << amount << " points." << '\n';
        std::cout << name << " has now " << hitPoint << " points." << '\n';
        std::cout << '\n';
        return ;
    }
    std::cout << "ScavTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

void    ScavTrap::setAttackDamage(int damage)
{
    std::cout << "\033[1;36m" << "[ScavTrap " << name << "'s Set Attack Damage Event]" << "\033[0m" << '\n';
    if (hitPoint == 0)
    {
        std::cout << "ScavTrap " << name << " was dead..." << '\n';
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
    std::cout << "ScavTrap " << name << " gets " << damage << " attack damage stat." << '\n';
    std::cout << '\n';
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " guards gates" << '\n';
    std::cout << '\n';
}
