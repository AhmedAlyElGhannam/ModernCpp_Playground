#ifndef BORROWABLE_HPP
#define BORROWABLE_HPP

#pragma once

#include <iostream>

class Borrowable 
{
    private:
        std::string itemName;
        std::string borrowDate;

    public:
        // virtual because it will be used polymorphically
        // to make sure this class resources are freed
        virtual ~Borrowable() {};
};


#endif 