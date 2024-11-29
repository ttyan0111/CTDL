#include "AccountModel.h"

// Constructor
AccountModel::AccountModel(const std::string& user, const std::string& pass)
    : username(user), password(pass) {}

// Getter cho tên đăng nhập
std::string AccountModel::getUsername() const {
    return username;
}

// Kiểm tra mật khẩu
bool AccountModel::checkPassword(const std::string& pass) const {
    return password == pass;
}
