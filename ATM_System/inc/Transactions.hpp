#pragma once
#include <iostream> // in/out stream
#include <sstream> // string stream
#include <vector> // container to save accounts && transactions
#include <memory> // for smart pointer (shared)
#include <string_view> // lightweight string lib
#include <algorithm> // sorting algorithms
#include <ctime> // get current time
#include <iomanip> // manipulation formating of time
#include "Time.hpp"
class Transaction
{
    public:
        std::string type;
        double amount;
        std::string timeStamp;

    Transaction(std::string_view type, double amount): type(type), amount(amount), timeStamp(getCurrentTime()) {}
};