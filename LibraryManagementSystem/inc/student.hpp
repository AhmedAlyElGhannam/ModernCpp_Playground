#ifndef STUDENT_HPP
#define STUDENT_HPP

#pragma once

#include <user.hpp>

class Student : public User 
{
    public:
        Student(std::string studentName, int studentID);
        // override indicates that this function overrides a virtual function in a base class
        void displayUserInfo() const override;

        ~Student() {}
};


#endif