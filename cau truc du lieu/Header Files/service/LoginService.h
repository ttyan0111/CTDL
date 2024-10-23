//
// Created by Yan on 10/10/2024.
//

#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

class LoginService {
private:
    std::unordered_map<std::string, std::string> userDatabase;

    void loadUsersFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Không thể mở tệp: " << filename << std::endl;
            return;
        }
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string username, password;
            if (getline(iss, username, ':') && getline(iss, password)) {
                userDatabase[username] = password;
                std::cout << "Read user: " << username << ", password: " << password << std::endl;  // Debug line
            }
        }
        file.close();
    }

public:
    // Khởi tạo mặc định
    LoginService() {
        loadUsersFromFile("users.txt"); // Đọc dữ liệu từ tệp
    }

    bool authenticate(const std::string& username, const std::string& password) {
        auto it = userDatabase.find(username);
        if (it == userDatabase.end()) {
            std::cout << "Tên đăng nhập không tồn tại.\n";
            return false;
        }
        if (it->second != password) {
            std::cout << "Mật khẩu không chính xác.\n";
            return false;
        }
        return true;
    }

};
#endif //LOGINSERVICE_H

