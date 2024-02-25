#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap a("Good");
    FragTrap b("Better");
    ClapTrap c(a);
    ScavTrap d("Wow");
    ClapTrap e(d);
    e = a;
    std::cout << '\n';

    std::cout << c.getAttackDamage() << '\n';
    std::cout << e.getAttackDamage() << '\n';
    a.highFivesGuys();
    b.highFivesGuys();
    for (int i=0; i<3; i++)
    {
        std::cout << "Simulation count : " << i + 1 << '\n';
        std::cout << "=========================================" << '\n';
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());
        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());
        std::cout << "=========================================" << '\n';
        std::cout << '\n';
    }
    a.beRepaired(59);
    b.attack(a.getName());
    a.takeDamage(b.getAttackDamage());
    return (0);
}
