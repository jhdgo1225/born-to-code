#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc [input your file]" << '\n';
        return (1);
    }
    BitcoinExchange::exhange(argv[1]);
    return (0);
}
