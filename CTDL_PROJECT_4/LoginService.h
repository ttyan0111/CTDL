#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H

#include <iostream>
#include <unordered_map>
#include <string>

class LoginService {
private:
    std::unordered_map<std::string, std::string> userDatabase;

    // Hàm đọc dữ liệu người dùng từ tệp
    void loadUsersFromFile(const std::string& filename);

public:
    // Khởi tạo mặc định
    LoginService();

    // Phương thức xác thực người dùng
    bool authenticate(const std::string& username, const std::string& password);
};

#endif // LOGINSERVICE_H
