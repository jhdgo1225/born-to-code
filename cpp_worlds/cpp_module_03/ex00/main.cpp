#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Clap A");
    ClapTrap b("Clap B");
    std::cout << '\n';

    b.setAttackDamage(2147483647);

    a.attack("Clap B");
    b.takeDamage(a.getAttackDamage());

    // b.beRepaired(100);

    for (int i=0; i<12; i++)
    {
        b.attack("Clap A");
        a.takeDamage(b.getAttackDamage());
    }

    a.beRepaired(10);
    b.beRepaired(1);
    return (0);
}
