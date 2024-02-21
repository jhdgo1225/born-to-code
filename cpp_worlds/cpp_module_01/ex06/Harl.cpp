#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    print(std::string msg)
{
    std::cout << msg << '\n';
}

void    Harl::debug(void)
{
    print("[ DEBUG ]");
    print("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.");
    print("I really do!");
    print("");
}

void    Harl::info(void)
{
    print("[ INFO ]");
    print("I cannot believe adding extra bacon costs more money.");
    print("You didn’t put enough bacon in my burger!");
    print("If you did, I wouldn’t be asking for more!");
    print("");
}

void    Harl::warning(void)
{
    print("[ WARNING ]");
    print("I think I deserve to have some extra bacon for free.");
    print("I’ve been coming for years whereas you started working here since last month.");
    print("");
}

void    Harl::error(void)
{
    print("[ ERROR ]");
    print("This is unacceptable! I want to speak to the manager now.");
    print("");
}

void    Harl::complain(std::string level)
{
    int num = -1;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i=0; i<4; i++)
    {
        if (!level.compare(levels[i]))
        {
            num = i;
            break ;
        }
    }
    switch(num)
    {
        case 0:
            debug();
            [[fallthrough]];
        case 1:
            info();
            [[fallthrough]];
        case 2:
            warning();
            [[fallthrough]];
        case 3:
            error();
            break ;
        default:
            print("[ Probably complaining about insignificant problems ]");
            break ;
    }
}
