#pragma once

#include "Account.hpp"

class ATM
{
    private:
        std::vector<std::shared_ptr<Account>> accounts;

    public:
        void addAccount(std::string_view accountNumber, int PIN, double initialBalance)
        {
            accounts.emplace_back(std::make_shared<Account>(accountNumber, PIN, initialBalance));
        }

        std::shared_ptr<Account> authenticate(std::string_view accountNumber, int pinNum)
        {
            // to do (accountNumber && pinNumber)
            for (const auto & accountIter : accounts)
            {
                if (accountIter->authenticate(pinNum))
                {
                    std::cout << "Authentication Successful!\n";
                    return accountIter;
                }
            }

            std::cout << "Authentication Failed!\n";
            return nullptr;
        }
};