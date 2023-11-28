// loan.cpp
#include "loan.h"
#include <iostream>
#include <windows.h>
#include <thread> // Thư viện để sử dụng std::this_thread::sleep_for
#include <iomanip>  // Thêm thư viện này để sử dụng std::setw và std::left

Loan::Loan() {}

Loan::Loan(std::string loanID, std::string userID, std::string bookID, std::string startDate, std::string dueDate, std::string status)
    : loanID(loanID), userID(userID), bookID(bookID), startDate(startDate), dueDate(dueDate), status(status) {}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printLoadingAnimation(int duration, bool& animationComplete) {
    const int steps = 100;
    const int sleepDuration = duration / steps;

    for (int i = 0; i <= steps; ++i) {
        setColor(10); // Màu xanh lá cây
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
    setColor(7);  // Trả lại màu mặc định

    // Đặt biến kiểm soát về true khi animation hoàn thành
    animationComplete = true;
}

void Loan::view() const {
    std::cout << "Loan ID: " << loanID << std::endl;
    std::cout << "User ID: " << userID << std::endl;
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Start Date: " << startDate << std::endl;
    std::cout << "Due Date: " << dueDate << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "-------------------------" << std::endl;
}


void Loan::listLoans(const std::vector<Loan>& loans) {
    bool animationComplete = false;
    printLoadingAnimation(1000, animationComplete);  // Thời gian animation: 1000ms (1 giây)

    if (animationComplete) {
        if (loans.empty()) {
            setColor(12);  // Màu đỏ
            std::cout << "Danh sach khong co gi ca." << std::endl;
            setColor(7);  // Trả lại màu mặc định
        }
        else {
            for (const auto& loan : loans) {
                loan.view();
            }
        }
    }
}
void Loan::searchLoan(const std::vector<Loan>& loans) {
    std::string searchLoanID;
    std::cout << "Enter the Loan ID to search for: ";
    std::cin >> searchLoanID;

    bool found = false;
    for (const auto& loan : loans) {
        if (loan.loanID == searchLoanID) {
            loan.view();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Không tìm thấy phiếu mượn" << std::endl;
    }
}
void Loan::viewLoan(const std::vector<Loan>& loans) {
    std::string loanID;
    std::cout << "Input Loan ID: ";
    std::cin >> loanID;

    auto loanIt = std::find_if(loans.begin(), loans.end(), [loanID](const Loan& loan) { return loan.loanID == loanID; });
    if (loanIt != loans.end()) {
        loanIt->view();
    }
    else {
        std::cout << "Lỗi: Không tìm thấy phiếu mượn" << std::endl;
    }
}

void Loan::addLoan(std::vector<Loan>& loans, const std::vector<User>& users, const std::vector<Book>& books) {
    std::string loanID, userID, bookID, startDate, dueDate, status;

    std::cout << "Input Loan ID: ";
    std::cin >> loanID;

    std::cout << "Input User ID: ";
    std::cin >> userID;

    // Kiểm tra userID
    auto userIt = std::find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (userIt == users.end()) {
        std::cout << "Error: Cannot found User" << std::endl;
        return;
    }

    std::cout << "Input Book ID: ";
    std::cin >> bookID;

    // Kiểm tra bookID
    auto bookIt = std::find_if(books.begin(), books.end(), [bookID](const Book& book) { return book.bookID == bookID; });
    if (bookIt == books.end()) {
        std::cout << "Error: Cannot found book" << std::endl;
        return;
    }

    std::cout << "Input Start Date: ";
    std::cin >> startDate;
    std::cout << "Input Due Date: ";
    std::cin >> dueDate;
    std::cout << "Input Status: ";
    std::cin >> status;

    loans.push_back(Loan(loanID, userID, bookID, startDate, dueDate, status));

    std::cout << "Success" << std::endl;
}

void Loan::deleteLoan(std::vector<Loan>& loans) {
    std::string deleteLoanID;
    std::cout << "Enter the Loan ID to delete: ";
    std::cin >> deleteLoanID;

    auto it = std::remove_if(loans.begin(), loans.end(),
        [deleteLoanID](const Loan& loan) { return loan.loanID == deleteLoanID; });

    if (it != loans.end()) {
        loans.erase(it, loans.end());
        setColor(12);  // Màu đỏ
        std::cout << "Delete Success" << std::endl;
    }
    else {
        std::cout << "Cannot found" << std::endl;
    }
}