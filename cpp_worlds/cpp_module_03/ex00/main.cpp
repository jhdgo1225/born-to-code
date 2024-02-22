#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("sibal");
    ClapTrap b("normdle");

    b.setAttackDamage(2147483647);

    b.attack("sibal");
    a.takeDamage(b.getAttackDamage());

    b.attack("sibal");
    a.takeDamage(b.getAttackDamage());

    a.attack("normdle");
    b.takeDamage(a.getAttackDamage());

    return (0);
}