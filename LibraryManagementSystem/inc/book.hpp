#ifndef BOOK_HPP
#define BOOK_HPP

#pragma once

#include "borrowable.hpp"

class Book : public Borrowable
{
    private:
        std::string bookName;
        int bookID;
        std::string bookAuthor;
        bool isAvailable;

    public:
        Book(std::string _bookName, int _bookID, std::string _bookAuthor);

        // const methods to ensure immutability + can be called for const objects
        void displayBookInfo() const;
        bool checkAvailablility() const;

        void borrowBook();
        void returnBook();

        ~Book()
        {

        }
};

#endif 