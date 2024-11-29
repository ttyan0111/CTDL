#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class AccountModel {
private:
    std::string username; // Tên đăng nhập
    std::string password; // Mật khẩu

public:
    // Constructor
    AccountModel(const std::string& user, const std::string& pass);

    // Getter cho tên đăng nhập
    std::string getUsername() const;

    // Kiểm tra mật khẩu
    bool checkPassword(const std::string& pass) const;
};

#endif // ACCOUNT_H
