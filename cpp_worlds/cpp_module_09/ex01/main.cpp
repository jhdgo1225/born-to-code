#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN [Reverse Polish Notation]" << '\n';
        return (1);
    }
    std::string notation(argv[1]);
    RPN::calculate(notation);
    return (0);
}
