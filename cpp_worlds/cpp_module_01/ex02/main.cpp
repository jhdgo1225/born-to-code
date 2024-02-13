#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "\033[1;31m" << "Check Address!" << "\033[0m" << '\n';
    std::cout << &brain << '\n';
    std::cout << stringPTR << '\n';
    std::cout << &stringREF << '\n';

    std::cout << "\033[1;34m" << "\nCheck Value!" << "\033[0m" << '\n';
    std::cout << brain << '\n';
    std::cout << *stringPTR << '\n';
    std::cout << stringREF << '\n';
    return (0);
}
