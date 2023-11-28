// user.cpp
#include "user.h"
#include <iostream>

User::User() {}

User::User(std::string username, std::string password, std::string name, std::string address, std::string phone, std::string userID)
    : username(username), password(password), name(name), address(address), phone(phone), userID(userID){}

void User::view() const {
    std::cout << "UserID: " << userID << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone: " << phone << std::endl;
}

bool User::searchByName(const std::string& searchName) const {
    return name == searchName;
}

void listUsers(const std::vector<User>& users) {
    // Cài đặt hàm liệt kê người dùng
    for (const auto& user : users) {
        user.view();
    }
}

void searchUser(const std::vector<User>& users) {
    // Cài đặt hàm tìm kiếm người dùng
    std::string searchName;
    std::cout << "Enter the name to search: ";
    std::cin >> searchName;

    bool found = false;
    for (const auto& user : users) {
        if (user.searchByName(searchName)) {
            user.view();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Not Found User" << std::endl;
    }
}

void viewUser(const std::vector<User>& users) {
    // Cài đặt hàm xem thông tin người dùng
    int index;
    std::cout << "Enter the index of the user to view: ";
    std::cin >> index;

    if (index >= 0 && index < users.size()) {
        users[index].view();
    }
    else {
        std::cout << "Not Found User" << std::endl;
    }
}

void addUser(std::vector<User>& users) {
    // Cài đặt hàm thêm người dùng
    std::string username, password, name, address, phone, userID;

    std::cout << "Input UserName: ";
    std::cin >> username;
    std::cout << "Input userID: ";
    std::cin >> userID;
    std::cout << "Input password: ";
    std::cin >> password;
    std::cout << "Input Name: ";
    std::cin >> name;
    std::cout << "Input address: ";
    std::cin >> address;
    std::cout << "Input phone: ";
    std::cin >> phone;

    users.push_back(User(username, password, name, address, phone,userID));

    std::cout << "Success to add user" << std::endl;
}

void deleteUser(std::vector<User>& users) {
    // Cài đặt hàm xóa người dùng
    int index;
    std::cout << "Enter the index of the user to delete: ";
    std::cin >> index;

    if (index >= 0 && index < users.size()) {
        users.erase(users.begin() + index);
        std::cout << "Delete User" << std::endl;
    }
    else {
        std::cout << "Cannot find user to delete" << std::endl;
    }
}