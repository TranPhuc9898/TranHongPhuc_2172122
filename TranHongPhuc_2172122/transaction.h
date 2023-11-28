// Trong transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "user.h"
#include "book.h"
#include "loan.h"

class Transaction {
public:
    // Getter methods
    std::string getTransactionID() const;
    std::string transactionID;
    std::string loanID;
    std::string bookID;
    std::string userID;
    std::string name;
    std::string description;

    Transaction();

    Transaction(std::string transactionID, std::string loanID, std::string bookID, std::string userID, std::string name, std::string description);

   static void addTransaction(std::vector<Transaction>& transactions, const std::vector<User>& users, const std::vector<Book>& books, const std::vector<Loan>& loans);

    static void listTransactions(const std::vector<Transaction>& transactions);

    static void viewTransaction(const Transaction& transaction);
    // Function to search for a transaction
    std::string searchTransaction(const std::vector<Transaction>& transactions, const std::string& transactionID, Transaction& foundTransaction);

    // Function to delete a transaction
    std::string deleteTransaction(std::vector<Transaction>& transactions, const std::string& transactionID);

};

#endif // TRANSACTION_H