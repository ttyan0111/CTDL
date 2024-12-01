#include "LoginService.h"
#include <fstream>
#include <sstream>

// Hàm đọc dữ liệu người dùng từ tệp
void LoginService::loadUsersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Khong the mo tep: " << filename << std::endl;
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

// Khởi tạo mặc định
LoginService::LoginService() {
    loadUsersFromFile("users.txt"); // Đọc dữ liệu từ tệp
}

// Phương thức xác thực người dùng
bool LoginService::authenticate(const std::string& username, const std::string& password) {
    auto it = userDatabase.find(username);
    if (it == userDatabase.end()) {
        goToXY(28, 20);
        setColor(12, 0);
        std::cout << "Ten dang nhap khong ton tai.\n";
        setColor(7, 0);
        return false;
    }
    if (it->second != password) {
        goToXY(28, 20);
        setColor(12, 0);
        std::cout << "Mat khau khong chinh xac.\n";
        setColor(7, 0);
        return false;
    }
    return true;
}
