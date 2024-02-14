#include "Harl.hpp"

int main(void)
{
    Harl man1;
    Harl man2;

    std::cout << "\033[1;35m" << "Harl man1 has many complains" << "\033[0m" << '\n';
    std::cout << "===============================================================================================================================================\n";
    man1.complain("DEBUG");
    man1.complain("INFO");
    man1.complain("WARNING");
    man1.complain("INFORMATION");

    std::cout << '\n';
    std::cout << "\033[1;35m" << "Harl man2 has many complains, too" << "\033[0m" << '\n';
    std::cout << "===============================================================================================================================================\n";
    man2.complain("ERROR");
    man2.complain("ERRNO");
    man2.complain("INFO");
    man2.complain("DEBUG");
}