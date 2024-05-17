#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

class BitcoinExchange
{
public:
    static void exchange(const std::string& databaseFile);
private:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& rhs);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
}

#endif
