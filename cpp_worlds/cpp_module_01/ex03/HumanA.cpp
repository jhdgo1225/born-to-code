#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : name(name),
      weaponA(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weaponA.getType() << '\n';
}
