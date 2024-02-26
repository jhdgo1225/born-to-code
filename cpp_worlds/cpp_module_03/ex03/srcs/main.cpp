#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a("hi");
	DiamondTrap b(a);
	std::cout << '\n';

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(100);
	b.setAttackDamage(500);
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());

	a.guardGate();
	b.highFivesGuys();
	a.whoAmI();
	b.whoAmI();
	return (0);
}
