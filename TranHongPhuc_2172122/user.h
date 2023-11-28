// user.h
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
    std::string userID;
    std::string username;
    std::string password;
    std::string name;
    std::string address;
    std::string phone;

    User();
    User(std::string username, std::string password, std::string name, std::string address, std::string phone, std::string userID);

    void view() const;
    bool searchByName(const std::string& searchName) const;
};

void listUsers(const std::vector<User>& users);
void searchUser(const std::vector<User>& users);
void viewUser(const std::vector<User>& users);
void addUser(std::vector<User>& users);
void deleteUser(std::vector<User>& users);

#endif // USER_H