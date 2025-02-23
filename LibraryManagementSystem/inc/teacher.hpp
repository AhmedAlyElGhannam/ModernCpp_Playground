#ifndef TEACHER_HPP
#define TEACHER_HPP

#pragma once

#include "user.hpp"


class Teacher : public User 
{
    public:
        Teacher(std::string teacherName, int teacherID);
        void displayUserInfo() const override;
        ~Teacher() {}
};


#endif 