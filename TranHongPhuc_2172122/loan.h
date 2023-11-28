// loan.h
#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <vector>
#include "user.h"
#include "book.h"

class Loan {
public:
    std::string loanID;
    std::string userID;
    std::string bookID;
    std::string startDate;
    std::string dueDate;
    std::string status;

    Loan();
    Loan(std::string loanID, std::string userID, std::string bookID, std::string startDate, std::string dueDate, std::string status);

    void view() const;

    static void listLoans(const std::vector<Loan>& loans);
    static void searchLoan(const std::vector<Loan>& loans);
    static void viewLoan(const std::vector<Loan>& loans);
    static void addLoan(std::vector<Loan>& loans, const std::vector<User>& users, const std::vector<Book>& books);
    static void deleteLoan(std::vector<Loan>& loans);
};

#endif // LOAN_H