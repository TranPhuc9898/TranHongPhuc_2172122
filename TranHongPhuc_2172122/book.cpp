// book.cpp
#include "book.h"
#include "user.h"

std::string Book::getId() const {
    // Thực hiện logic để lấy ID của sách (ví dụ: có thể trả về bookID)
    return bookID;
}

std::string Book::getBookId() const {
    // Thực hiện logic để lấy trường bookID của sách
    return bookID;
}
void Book::view() const {
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void Book::listBooks(const std::vector<Book>& books) {
    for (int i = 0; i < books.size(); i++) {
        std::cout << "Index: " << i << std::endl;
        books[i].view();
    }
}

void Book::searchBook(const std::vector<Book>& books) {
    std::string searchTitle;
    std::cout << "Enter the title to search for: ";
    std::cin.ignore(); // Clear the newline from the input buffer
    std::getline(std::cin, searchTitle);

    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(searchTitle) != std::string::npos) {
            book.view();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Not found book" << std::endl;
    }
}

void Book::addBook(std::vector<Book>& books) {
    std::string bookID, title, author;

    std::cout << "Input Book ID: ";
    std::cin >> bookID;
    std::cout << "Input Title: ";
    std::cin.ignore(); // Clear the newline from the input buffer
    std::getline(std::cin, title);
    std::cout << "Input Author: ";
    std::cin.ignore(); // Clear the newline from the input buffer
    std::getline(std::cin, author);

    books.push_back(Book(bookID, title, author));

    std::cout << "Add book success" << std::endl;
}

void Book::deleteBook(std::vector<Book>& books) {
    int index;
    std::cout << "Enter the index of the book to delete: ";
    std::cin >> index;

    if (index >= 0 && index < books.size()) {
        books.erase(books.begin() + index);
        std::cout << "Delete Success" << std::endl;
    }
    else {
        std::cout << "Cannot Found book" << std::endl;
    }
}

void Book::editBook(std::vector<Book>& books) {
    int index;
    std::cout << "Enter the index of the book to edit: ";
    std::cin >> index;

    if (index >= 0 && index < books.size()) {
        std::string title, author;

        std::cout << "Input Title new: ";
        std::cin.ignore(); // Clear the newline from the input buffer
        std::getline(std::cin, title);
        std::cout << "Input Author new: ";
        std::cin.ignore(); // Clear the newline from the input buffer
        std::getline(std::cin, author);

        books[index] = Book(books[index].bookID, title, author);

        std::cout << "Edit book" << std::endl;
    }
    else {
        std::cout << "Cannot found book" << std::endl;
    }
}