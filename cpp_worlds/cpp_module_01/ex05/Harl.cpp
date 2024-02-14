#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << '\n';
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << '\n';
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << '\n';
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void    Harl::complain(std::string level)
{
    int num = -1;
    void    (Harl::*f)(void);
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
            f = &Harl::debug;
            break ;
        case 1:
            f = &Harl::info;
            break ;
        case 2:
            f = &Harl::warning;
            break ;
        case 3:
            f = &Harl::error;
            break ;
        default:
            f = 0;
            break ;
    }
    if (!f)
    {
        std::cout << "Harl doesn't have unnecessary comment" << '\n';
        return ;
    }
    (this->*f)();
}
