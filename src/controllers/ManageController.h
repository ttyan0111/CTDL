//
// Created by Yan on 09/10/2024.
//

#ifndef MANAGE_H
#define MANAGE_H

#include <iostream>
#include <string>
#include "../service/LoginService.h"
#include <conio.h>

class ManagerController {
private:
    LoginService loginService;

public:
    // Khởi tạo mặc định
    ManagerController() : loginService() {
        // Đọc thông tin người dùng từ tệp trong lớp LoginService
    }

    // Hàm để thực hiện đăng nhập
    bool login() {
        std::string usernameInput;
        std::string passwordInput;
        while (true) {
            system("cls"); // Xóa màn hình (trên Windows)
            std::cout << "Nhập tên đăng nhập: ";
            std::getline(std::cin, usernameInput);
            std::cout << "Nhập mật khẩu: ";
            std::getline(std::cin, passwordInput);

            // Kiểm tra đăng nhập
            if (loginService.authenticate(usernameInput, passwordInput)) {
                return true;
            } else {
                std::cout << "User or Password not valid (Enter: retry, Esc: quit)\n";
            }

            char key = _getch(); // Bắt phím nhấn
            if (key == 27) {  // ESC key
                std::cout << "Đăng xuất..." << std::endl;
                return false;
            } else if (key == 13) {  // Enter key
                continue;  // Thử lại
            }
        }
    }
};



#endif // MANAGE_H
