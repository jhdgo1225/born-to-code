#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name"),
	 ScavTrap(name),
	 FragTrap(name),
	 name(name)
{
	std::cout << "<< DiamondTrap " << name << " is Created!! >>" << '\n';
	this->hitPoint = FragTrap::fragTrapHitPoints;
	this->energyPoint = ScavTrap::scavTrapEnergyPoints;
	this->attackDamage = FragTrap::fragTrapAttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "<< DiamondTrap " << name << " is Destroyed!! >>" << '\n';
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	:ClapTrap(obj.name + "_clap_name"),
	 ScavTrap(obj.name),
	 FragTrap(obj.name),
	 name(obj.name)
{
	std::cout << "<< DiamondTrap " << name << " is Created!! >>" << '\n';
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	this->ClapTrap::name = obj.ClapTrap::name;
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	return *this;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "My(DiamondTrap) name is [ " << name << " ]" << '\n';
    std::cout << "My GrandParents(ClapTrap) name is [ " << ClapTrap::name << " ]" << '\n';
    std::cout << '\n';
}
