// book.h
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>

class User; // Forward declaration to avoid circular dependencies

class Book {
public:
    std::string bookID;
    std::string title;
    std::string author;

    Book() {}

    Book(std::string bookID, std::string title, std::string author)
        : bookID(bookID), title(title), author(author) {}

    void view() const;
    static void listBooks(const std::vector<Book>& books);
    static void searchBook(const std::vector<Book>& books);
    static void addBook(std::vector<Book>& books);
    static void deleteBook(std::vector<Book>& books);
    static void editBook(std::vector<Book>& books);

    // Thêm các phương thức mới
    std::string getId() const;
    std::string getBookId() const;
};

#endif // BOOK_H