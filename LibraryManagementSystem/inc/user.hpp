#ifndef USER_HPP
#define USER_HPP

#pragma once

#include <iostream>

class User 
{
    protected:
        // deez will be inherited by other classes
        std::string userName;
        int userID;

    public:
        User();
        User(std::string userName, int userID);

        virtual ~User();
        virtual void displayUserInfo() const;
};



#endif