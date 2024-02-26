#include "ScavTrap.hpp"

const int ScavTrap::scavTrapEnergyPoints = 50;

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
        energyPoint -= 1;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << '\n';
        std::cout << "The EnergyPoint of ScavTrap " << name << " is " << energyPoint << " points" << '\n';
        std::cout << '\n';
        return ;
    }
    std::cout << "ScavTrap " << name << " doesn't attack because of no Energy Point." << '\n';
    std::cout << '\n';
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " guards gates" << '\n';
    std::cout << '\n';
}
