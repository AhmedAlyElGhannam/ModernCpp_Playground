#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#pragma once

#include "book.hpp"
#include "user.hpp"
#include <vector>

class Library
{
    private:
        // composition: (has-a) + strong relationship
        // (owns it)
        // both have the same lifetime
        std::vector<Book> books; 

        // Aggregation (has-a) + weak relationship
        // (does not own it)
        // aggregated object can still exist after container destruction
        std::vector<User*> users;

    public:
        void addBook(const Book & _book);
        void addUser(User* user);
        void displayBooks() const;
        void displayUsers() const;
};

#endif 