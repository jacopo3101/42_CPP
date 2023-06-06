#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;
int Account::_totalAmount;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount  << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount  << ";closed" << std::endl;
}

int Account::checkAmount(void) const
{
    return (_amount);
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
   // [19920104_091532] // YYYYMMDD_HHMMSS
    std::time_t result = std::time(NULL);
    tm *time = std::localtime(&result);
    std::cout << "[" << time->tm_year + 1900 << time->tm_mon + 1
        << time->tm_mday << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";" << "total:" << Account::_totalAmount  << ";"
        << "deposits:" << Account::_totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
}
// instance function

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount  << ";" << "deposits:" << _nbDeposits  
        << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposit:" << deposit
        << ";" << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:";
    if( withdrawal <= _amount)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        std::cout << withdrawal << ";" << "amount:" << _amount << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << "refused" << std::endl;
        return false;
    }
}