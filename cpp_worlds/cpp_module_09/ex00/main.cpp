#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc [input your file]" << '\n';
        return (1);
    }
    std::string inputDBFile(argv[1]);
    BitcoinExchange::exchange(inputDBFile);
    return (0);
}
