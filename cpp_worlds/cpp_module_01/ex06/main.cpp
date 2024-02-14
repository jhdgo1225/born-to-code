#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        print("[ Harl needs only one problem ]");
        return (1);
    }
    Harl one;
    one.complain(argv[1]);
    return (0);
}