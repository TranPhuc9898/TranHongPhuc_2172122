#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "book.h"  // Thêm include cho class Book
#include "user.h"  // Thêm include cho class User
#include "loan.h"
#include "transaction.h" // Thêm include cho class Loan
#include <algorithm> // for std::find_if

Transaction::Transaction() {}


// Getter method definitions
std::string Transaction::getTransactionID() const {
    return Transaction::transactionID;
}


Transaction::Transaction(std::string transactionID, std::string loanID, std::string bookID, std::string userID, std::string name, std::string description)
    : transactionID(transactionID), loanID(loanID), bookID(bookID), userID(userID), name(name), description(description) {}

void setColor2(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printLoadingAnimation2(int duration, bool& animationComplete) {
    const int steps = 100;
    const int sleepDuration = duration / steps;

    for (int i = 0; i <= steps; ++i) {
        setColor2(10); // Màu xanh lá cây
        std::cout << "[";

        // In thanh trạng thái
        for (int j = 0; j < i; ++j) {
            std::cout << "=";
        }

        // In khoảng trắng còn lại
        for (int j = i; j < steps; ++j) {
            std::cout << " ";
        }

        std::cout << "] " << i << "%\r";
        std::cout.flush();

        Sleep(sleepDuration);  // Nghỉ giữa các bước
    }

    std::cout << std::endl;
    setColor2(7);  // Trả lại màu mặc định

    // Đặt biến kiểm soát về true khi animation hoàn thành
    animationComplete = true;
}


void Transaction::addTransaction(std::vector<Transaction>& transactions, const std::vector<User>& users, const std::vector<Book>& books, const std::vector<Loan>& loans) {
    std::string transactionID, loanID, bookID, userID, name, description;

    // Nhập thông tin giao dịch
    std::cout << "Enter Transaction ID: ";
    std::cin >> transactionID;

    std::cout << "Enter Loan ID: ";
    std::cin >> loanID;

    // Kiểm tra xem Loan ID có tồn tại không
    auto loanIt = std::find_if(loans.begin(), loans.end(), [loanID](const Loan& loan) { return loan.loanID == loanID; });
    if (loanIt == loans.end()) {
        std::cerr << "Khong co Loan ID nay." << std::endl;
        return;
    }

    std::cout << "Enter Book ID: ";
    std::cin >> bookID;

    // Kiểm tra xem Book ID có tồn tại không
    auto bookIt = std::find_if(books.begin(), books.end(), [bookID](const Book& book) { return book.bookID == bookID; });
    if (bookIt == books.end()) {
        std::cerr << "Khong co Book ID nay." << std::endl;
        return;
    }

    std::cout << "Enter User ID: ";
    std::cin >> userID;

    // Kiểm tra xem User ID có tồn tại không
    auto userIt = std::find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (userIt == users.end()) {
        std::cerr << "Khong co User ID nay." << std::endl;
        return;
    }

    std::cout << "Enter User Name: ";
    std::cin >> name;

    // Kiểm tra xem Name có tồn tại không
    auto nameIt = std::find_if(users.begin(), users.end(), [&name](const User& user) { return user.name == name; });
    if (nameIt == users.end()) {
        std::cerr << "Khong co ten nay." << std::endl;
        return;
    }

    std::cout << "Enter Description: ";
    std::cin.ignore(); // Đọc bỏ ký tự '\n' trong buffer
    std::getline(std::cin, description);

    // Thêm giao dịch mới vào danh sách
    transactions.push_back(Transaction(transactionID, loanID, bookID, userID, name, description));

    std::cout << "Giao dich da duoc them." << std::endl;
}

void Transaction::listTransactions(const std::vector<Transaction>& transactions) {
    bool animationComplete = false;
    printLoadingAnimation2(1000, animationComplete);

    if (animationComplete) {
        if (transactions.empty()) {
            setColor2(12);
            std::cout << "Danh sach giao dich khong co gi ca." << std::endl;
            setColor2(7);
        }
        else {
            // Header
            std::cout << "--------------------------------------------------------" << std::endl;
            std::cout << std::setw(15) << "| Transaction ID" << std::setw(15) << "| Loan ID" << std::setw(15) << "| Book ID" << std::setw(15) << "| User ID" << std::setw(15) << "| Name" << std::setw(15) << "| Description" << std::endl;
            std::cout << "|--------------------------------------------------------|" << std::endl;

            // Data
            for (const auto& transaction : transactions) {
                viewTransaction(transaction);
            }

            // Footer
            std::cout << "--------------------------------------------------------" << std::endl;
        }
    }
}

void Transaction::viewTransaction(const Transaction& transaction) {
    // Data
    std::cout << std::setw(0) << "|" << transaction.transactionID
        << std::setw(10) << "|  " << transaction.loanID
        << std::setw(10) << "|  " << transaction.bookID
        << std::setw(10) << "|  " << transaction.userID
        << std::setw(10) << "|  " << transaction.name
        << std::setw(10) << "|  " << transaction.name << std::endl;
}


// Function to search for a transaction
std::string Transaction::searchTransaction(const std::vector<Transaction>& transactions, const std::string& transactionID, Transaction& foundTransaction) {
    auto it = std::find_if(transactions.begin(), transactions.end(), [transactionID](const Transaction& transaction) {
        return transaction.getTransactionID() == transactionID;
        });

    if (it != transactions.end()) {
        foundTransaction = *it; // Copy found transaction
        return "Found Transaction";
    }
    else {
        return "Not Found Transaction";
    }
}


// Function to delete a transaction
std::string Transaction::deleteTransaction(std::vector<Transaction>& transactions, const std::string& transactionID) {
    auto it = std::remove_if(transactions.begin(), transactions.end(), [transactionID](const Transaction& transaction) {
        return transaction.getTransactionID() == transactionID;
        });

    if (it != transactions.end()) {
        transactions.erase(it, transactions.end());
        return "Delete Success";
    }
    else {
        return "Cannot Found";
    }
}

