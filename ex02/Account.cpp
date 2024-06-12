#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";amount:" << deposit << ";created" << std::endl;
    this->_amount = deposit;
    this->_accountIndex = _nbAccounts;
    _totalAmount += deposit;
    _nbAccounts++;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= this->_amount;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdraw)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (withdraw > this->_amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdraw;
    this->_nbWithdrawals++;
    _totalAmount -= withdraw;
    _totalNbWithdrawals++;
    std::cout << withdraw << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    return true;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    char buffer[17];
    buffer[16] = 0;

    std::strftime(buffer, sizeof(buffer) - 1, "%Y%m%d_%H%M%S", std::localtime(&now));
    std::cout << "[" << buffer << "] ";
}
