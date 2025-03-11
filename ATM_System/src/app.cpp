#include <iostream> // in/out stream
#include <sstream> // string stream
#include <vector> // container to save accounts && transactions
#include <memory> // for smart pointer (shared)
#include <string_view> // lightweight string lib
#include <algorithm> // sorting algorithms
#include <ctime> // get current time
#include <iomanip> // manipulation formating of time

#include "Transactions.hpp"
#include "Account.hpp"
#include "ATM.hpp"


int main()
{
    ATM atm;
    atm.addAccount("123", 4269, 1006.0);

    std::string accNum;
    int pinNum;

    std::cout << "Enter Account Number: \n";
    std::cin >> accNum;
    std::cout << "Enter PIN: \n";
    std::cin >> pinNum;

    auto account = atm.authenticate(accNum, pinNum);

    if (!account)
    {
        return 0;
    }
    
    auto performAction = [&](std::string_view action, double amount = 0)
    {
        if (action == "deposite")
        {
            account->deposite(amount);
        }
        else if (action == "withdraw")
        {
            account->withdraw(amount);
        }
        else if (action == "balance")
        {
            account->displayBalance();
        }
        else if (action == "history")
        {
            account->showTransactionHistory();
        }
        else if (action == "sort")
        {
            account->sortTransactionsByAmount();
        }
        else 
        {
            std::cout << "Invalid Action!\n";
        }
    };

    performAction("deposite", 500);
    performAction("withdraw", 500);
    performAction("balance");
    performAction("history");

    return 0;
}