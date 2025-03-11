#pragma once

#include <iostream> // in/out stream
#include <sstream> // string stream
#include <vector> // container to save accounts && transactions
#include <memory> // for smart pointer (shared)
#include <string_view> // lightweight string lib
#include <algorithm> // sorting algorithms
#include <ctime> // get current time
#include <iomanip> // manipulation formating of time
#include "Transactions.hpp"

class Account 
{
    private:
        std::string accountNumber;
        int PIN;
        double balance;
        std::vector<Transaction> transactions;

    public:
        Account(std::string_view accountNumber, int PIN, double initialBalance) : accountNumber(accountNumber), PIN(PIN), balance(initialBalance) {}

        bool authenticate(int pinNumber) const 
        {
            return (PIN == pinNumber);
        }

        void deposite(double amount) 
        {
            if (amount > 0)
            {
                balance += amount;
                transactions.emplace_back("Deposite", amount);
                std::cout << "Deposite Successful!\nNew Balance: " 
                          << balance << " $\n";
            }
            else 
            {
                std::cout << "Nice try, jacka$$! \nNext time, give it your A-game!\n";
            }
                
        }

        bool withdraw(double amount)
        {
            bool isSuccessfulOperation = true;
            if (amount > balance)
            {
                std::cout << "Insufficient Balance!\n";
                isSuccessfulOperation = false;
            }
            else 
            {
                balance -= amount;
                std::cout << "Withdrawal Successful!\nRemaining Balance: " << balance << " $\n"; 
            }

            return isSuccessfulOperation;
        }

        void showTransactionHistory() const 
        {
            std::cout << "Transaction History for Account "
                      << accountNumber << ":\n";

            for (const auto & transactionsIter : transactions)
            {
                std::cout << transactionsIter.type 
                          << " of "
                          << transactionsIter.amount
                          << " $ "
                          << "on "
                          << transactionsIter.timeStamp 
                          << "\n";
            }
        }

        void sortTransactionsByAmount()
        {
            std::sort(transactions.begin(), transactions.end(), [](const Transaction & a, const Transaction & b)
                { return a.amount < b.amount; } // sort ascendingly
            );

            std::cout << "Transactions sorted ascendingly by amount\n";
        }

        void displayBalance() const 
        {
            std::cout << "Current Balance: "
                      << balance
                      << " $\n";
        }
};

