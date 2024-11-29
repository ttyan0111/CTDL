#ifndef MANAGE_H
#define MANAGE_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <conio.h>
#include <windows.h> // Thêm thư viện này để sử dụng SetConsoleCursorPosition

#include "LoginService.h"
#include "Display.h"

#include "OrderList.h"


class MenuManagerController {
private:
    Display display;
    LoginService loginService;
    std::atomic<bool> isLocked; // Trạng thái khóa (atomic cho thread-safe)
    std::atomic<int> remainingTime; // Thời gian khóa còn lại (giây)
    bool isLogin = false;


public:
    MenuManagerController();

    // Bắt đầu quản lý
    void start();

    // Xử lý lựa chọn sau khi đăng nhập thành công
    bool handleSelection();

    // Hàm chạy ngầm để đếm thời gian khóa
    void lockCountdown(int seconds);

    // Kiểm tra xem có đang bị khóa hay không
    bool isCurrentlyLocked();

    // Hàm xử lý đăng nhập
    bool login();

    // Kiểm tra thông tin đăng nhập
    bool checkLogin();
};

#endif // MANAGE_H
