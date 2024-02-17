#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts)
    , _amount(initial_deposit)
{
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";";
    _nbAccounts += 1;
    _amount = initial_deposit;
    std::cout << "amount:" << _amount << ";";
    _totalAmount += initial_deposit;
    std::cout << "created\n";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed\n";
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void    Account::_displayTimestamp(void)
{
    time_t temp;
    struct tm *timeinfo;
    char buff[256];

    time(&temp);
    timeinfo = localtime(&temp);
    strftime(buff, 256, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buff << ' ';
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << '\n';
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposits:";
    if (deposit < 0)
    {
        std::cout << "refused\n";
        return ;
    }
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << deposit << ";";
    std::cout << "amount:" << checkAmount() << ";";
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << "nb_deposits:" << _nbDeposits << '\n';
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "withdrawal:";
    if (withdrawal < 0 || _amount - withdrawal < 0)
    {
        std::cout << "refused\n";
        return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << withdrawal << ";";
    std::cout << "amount:" << checkAmount() << ";";
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << '\n';
    return (true);
}

int     Account::checkAmount(void) const
{
    return (_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}
