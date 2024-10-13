#ifndef MANAGE_H
#define MANAGE_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <conio.h>
#include "../service/LoginService.h"
#include "../view/Display.h"
#include <windows.h> // Thêm thư viện này để sử dụng SetConsoleCursorPosition

#include "MenuManage/MenuManageGoodsController.h"


class ManagerController {
private:
    Display display;
    LoginService loginService;
    std::atomic<bool> isLocked; // Trạng thái khóa (atomic cho thread-safe)
    std::atomic<int> remainingTime; // Thời gian khóa còn lại (giây)
    bool isLogin = false;
    MenuManagerGoodsController controller;
public:
    ManagerController() : isLocked(false), remainingTime(0) {
    }

    // Bắt đầu quản lý
    void start() {
        if (isLogin) {
            while (true) {
                display.displayManager();
                if (handleSelection()) {
                    break;
                }
            }
        } else if (isCurrentlyLocked()) {
        } else if (login()) {
            while (true) {
                display.displayManager();
                if (handleSelection()) {
                    break;
                }
            }
        } else {
            system("cls");
            std::cout << "Đăng nhập thất bại!\n";
            std::cout << "Nhấn phím ESC để quay lại menu chính..." << std::endl;
            while (true) {
                char key = _getch(); // Chờ nhấn phím bất kỳ để quay lại menu chính
                if (key == 27) {
                    break;
                }
            }
        }
    }
    // Xử lý lựa chọn sau khi đăng nhập thành công
    bool handleSelection() {
        system("cls");
        int selection = display.getSelectedManage();
        switch (selection) {
            case 0:
                std::cout << "Xử lý đơn hàng\n";
            break;
            case 1:
                std::cout << "Quản lý hàng hóa\n";
                controller.start();
                return false;
            case 2:
                return true;
            default:
                std::cout << "Lựa chọn không hợp lệ!\n";
            return false;
        }
        // std::cout << "Nhấn ESC để quay lại menu quản lý...\n";
        // while (true) {
        //     char key = _getch();
        //     if (key == 27) {
        //         return false;
        //     }
        // }
    }
    // Hàm chạy ngầm để đếm thời gian khóa
    void lockCountdown(int seconds) {
        isLocked = true;
        remainingTime = seconds;

        // Chạy luồng riêng để đếm ngược
        std::thread([this]() {
            while (remainingTime > 0) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                remainingTime--;
            }
            isLocked = false; // Mở khóa sau khi hết thời gian
        }).detach(); // Detach để luồng chạy ngầm
    }


    bool isCurrentlyLocked() {
        if (isLocked) {
            char key;
            key = 1;


            // Lưu vị trí của dòng hiển thị
            COORD cursorPos;
            cursorPos.Y = 0; // Vị trí Y của dòng hiển thị
            cursorPos.X = 0; // Vị trí X bắt đầu

            while (key != 27) {
                // Di chuyển con trỏ về vị trí mong muốn
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);

                // In lại dòng thông báo
                std::cout << "Chức năng đang bị khóa! Còn " << remainingTime << " giây... ";
                // Dấu cách để xóa thông tin cũ
                std::cout << "(Nhấn ESC để thoát)";
                std::cout << "\r"; // Di chuyển con trỏ về đầu dòng

                // Kiểm tra phím nhấn
                if (_kbhit()) {
                    key = _getch();
                    if (key == 27) {
                        // ESC key
                        return true; // Thoát khỏi khóa
                    }
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Tạm dừng để giảm tần suất cập nhật
            }
        }
        return false;
    }


    // Hàm xử lý đăng nhập
    bool login() {
        const int MAX_ATTEMPTS = 3;
        int attemptsLeft = MAX_ATTEMPTS;

        while (attemptsLeft > 0) {
            if (checkLogin()) {
                std::cout << "Đăng nhập thành công!\n";
                isLogin = true;

                return true;
            } else {
                attemptsLeft--;
                std::cout << "Sai thông tin đăng nhập! Còn "
                        << attemptsLeft << " lần thử.\n";

                if (attemptsLeft == 0) {
                    lockCountdown(300); // Khóa 5 phút (300 giây)
                    return false;
                }
            }
            std::cout << "Tiếp tục (Enter) hoặc Thoát (ESC): ";
            // Chờ người dùng nhấn Enter hoặc ESC
            while (true) {
                char key = _getch();
                if (key == 27) {
                    // ESC
                    return false;
                } else if (key == 13) {
                    // Enter
                    break;
                }
            }
        }
        return false;
    }




    // Kiểm tra thông tin đăng nhập
    bool checkLogin() {
        std::string username, password;
        system("cls");
        std::cout << "Nhập tên đăng nhập: ";
        std::getline(std::cin, username);
        std::cout << "Nhập mật khẩu: ";
        std::getline(std::cin, password);
        return loginService.authenticate(username, password);
    }
};

#endif // MANAGE_H
