#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("Good");
    ScavTrap b("Better");
    ScavTrap c(a);
    std::cout << '\n';

    a.guardGate();
    b.guardGate();
    for (int i=0; i<3; i++)
    {
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());
        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());
    }
    a.beRepaired(59);
    b.attack(a.getName());
    a.takeDamage(b.getAttackDamage());
    return (0);
}
