// main.cpp
#include <iostream>
#include <vector>
#include "user.h"
#include "book.h"
#include "loan.h"
#include "transaction.h"  
#include <limits> 

int main() {
    std::vector<User> users;
    std::vector<Book> books;
    std::vector<Loan> loans;
    std::vector<Transaction> transactions;

    int mainChoice;
    int userChoice;
    int bookChoice;
    int loanChoice;
    int transactionChoice; 
    do {
        std::cout << "===== MAIN MENU =====" << std::endl;
        std::cout << "1. Users" << std::endl;
        std::cout << "2. Books" << std::endl;
        std::cout << "3. Loans" << std::endl;
        std::cout << "4. Transactions" << std::endl;  // Thêm mục Transaction
        std::cout << "5. Say Goodbye" << std::endl;  // Đưa mục "Say Goodbye" xuống số 5
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;
        // Xóa bỏ ký tự thừa trong buffer
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (mainChoice) {
        case 1:
            do {
                std::cout << "===== USER MENU =====" << std::endl;
                std::cout << "1. List Users" << std::endl;
                std::cout << "2. Search User" << std::endl;
                std::cout << "3. View User" << std::endl;
                std::cout << "4. Add User" << std::endl;
                std::cout << "5. Delete User" << std::endl;
                std::cout << "0. Back to Main Menu" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> userChoice;

                switch (userChoice) {
                case 1:
                    listUsers(users);
                    break;
                case 2:
                    searchUser(users);
                    break;
                case 3:
                    viewUser(users);
                    break;
                case 4:
                    addUser(users);
                    break;
                case 5:
                    deleteUser(users);
                    break;
                case 0:
                    std::cout << "Returning to Main Menu." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (userChoice != 0);
            break;
        case 2:
            do {
                std::cout << "===== BOOK MENU =====" << std::endl;
                std::cout << "1. List Books" << std::endl;
                std::cout << "2. Search Book" << std::endl;
                std::cout << "3. Add Book" << std::endl;
                std::cout << "4. Delete Book" << std::endl;
                std::cout << "0. Back to Main Menu" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> bookChoice;
                // Xóa bỏ ký tự thừa trong buffer
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                switch (bookChoice) {
                case 1:
                    Book::listBooks(books);
                    break;
                case 2:
                    Book::searchBook(books);
                    break;
                case 3:
                    Book::addBook(books);
                    break;
                case 4:
                    Book::deleteBook(books);
                    break;
                case 0:
                    std::cout << "Returning to Main Menu." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (bookChoice != 0);
            break;
          case 3:
            do {
                std::cout << "===== LOAN MENU =====" << std::endl;
                std::cout << "1. List Loans" << std::endl;
                std::cout << "2. Search Loan" << std::endl;
                std::cout << "3. View Loan" << std::endl;
                std::cout << "4. Add Loan" << std::endl;
                std::cout << "5. Delete Loan" << std::endl;
                std::cout << "0. Back to Main Menu" << std::endl;
                std::cout << "Enter your choice: ";
              
                std::cin >> loanChoice;
                // Xóa bỏ ký tự thừa trong buffer
               //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (loanChoice) {
                case 1:
                    Loan::listLoans(loans);
                    break;
                case 2:
                    Loan::searchLoan(loans);
                    break;
                case 3:
                    Loan::viewLoan(loans);
                    break;
                case 4:
                    Loan::addLoan(loans, users, books);
                    break;
                case 5:
                    Loan::deleteLoan(loans);
                    break;
                case 0:
                    std::cout << "Returning to Main Menu." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (loanChoice != 0);
            break;
          case 4:
              // Menu cho giao dịch
              do {
                  std::cout << "===== TRANSACTION MENU =====" << std::endl;
                  std::cout << "1. List Transactions" << std::endl;
                  std::cout << "2. Add Transaction" << std::endl;
                  std::cout << "3. Search Transaction" << std::endl;
                  std::cout << "4. Delete Transaction" << std::endl;
                  std::cout << "5. Back to Main Menu" << std::endl;
                  std::cout << "Enter your choice: ";
                  std::cin >> transactionChoice;

                  Transaction transaction;  // Tạo một đối tượng Transaction để gọi các hàm thành viên không tĩnh
                  switch (transactionChoice) {
                  case 1:
                      transaction.listTransactions(transactions);
                      break;
                  case 2:
                      transaction.addTransaction(transactions, users, books, loans);
                      break;
                  case 3: {
                      std::string searchID;
                      std::cout << "Enter Transaction ID to search: ";
                      std::cin >> searchID;

                      Transaction foundTransaction;
                      std::string result = transaction.searchTransaction(transactions, searchID, foundTransaction);
                      std::cout << result << std::endl;

                      if (result == "Da Tim Thay") {
                          // Process foundTransaction if needed
                          transaction.viewTransaction(foundTransaction);
                      }
                      break;
                  }
                  case 4: {
                      std::string deleteID;
                      std::cout << "Enter Transaction ID to delete: ";
                      std::cin >> deleteID;

                      std::string result = transaction.deleteTransaction(transactions, deleteID);
                      std::cout << result << std::endl;
                      break;
                  }
                  case 5:
                      std::cout << "Returning to Main Menu." << std::endl;
                      break;
                  default:
                      std::cout << "Invalid choice. Please try again." << std::endl;
                  }
              } while (transactionChoice != 5);
              break;
          case 5:
              std::cout << "Saying Goodbye. Exiting program. Goodbye!" << std::endl;
              break;
          default:
              std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (mainChoice != 5);

    return 0;
}