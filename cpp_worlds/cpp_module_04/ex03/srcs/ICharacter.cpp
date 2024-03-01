#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "\033[1;32m" << "<< ICharacter Class is Created >>" << "\033[0m" << '\n';
}

ICharacter::~ICharacter()
{
	std::cout << "\033[1;31m" << "<< ICharacter Class is Destroyed >>" << "\033[0m" << '\n';
}
