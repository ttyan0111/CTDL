//
// Created by Yan on 10/10/2024.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class AccountModel {
private:
    std::string username = "admin"; // Tên đăng nhập
    std::string password = "admin"; // Mật khẩu

public:
    // Constructor
    AccountModel(const std::string &user, const std::string &pass) {
        username = user;
        password = pass;
    };

    // Getter cho tên đăng nhập
    std::string getUsername() const {return username;};

    // Kiểm tra mật khẩu
    bool checkPassword(const std::string &pass) const {return password == pass;};

    // Thêm các phương thức khác nếu cần
};

#endif // ACCOUNT_H
