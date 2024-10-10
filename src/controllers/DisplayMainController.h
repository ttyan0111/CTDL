//
// Created by Yan on 10/10/2024.
//

#ifndef DISPLAYMAINCONTROLLER_H
#define DISPLAYMAINCONTROLLER_H

#include "ManageController.h"
#include "../view/DisplayMain.h"
#include <conio.h>
class DisplayMainController {
private:
    DisplayMain displayMain;
    ManagerController managerController;
    bool isRunning;
    bool isLogin = false;
public:
    // Hàm khởi tạo
    DisplayMainController() : isRunning(true) {}

    void setDisplayMain(DisplayMain displayMain) {
        this->displayMain = displayMain; // Lưu trữ đối tượng DisplayMain
    }

    void start() {
        while (isRunning) {
            displayMain.displayMenu();
            handleSelection(); // Gọi hàm xử lý lựa chọn
        }
    }

    // Hàm xử lý khi chọn một mục trong menu
    void handleSelection() {
        clearScreen(); // Xóa màn hình
        int selection = displayMain.getSelectedIndex();
        switch (selection) {
            case 0:
                std::cout << "Hiển thị thông tin hàng hóa" << std::endl;
                // Thêm chức năng hiển thị thông tin hàng hóa ở đây
                break;
            case 1:
                std::cout << "Tìm kiếm thông tin hàng hóa" << std::endl;
                // Thêm chức năng tìm kiếm hàng hóa ở đây
                break;
            case 2:
                std::cout << "Đặt hàng" << std::endl;
                // Thêm chức năng đặt hàng ở đây
                break;
            case 3: {
                std::cout << "Quản lý" << std::endl;
                if(!isLogin) {
                    if (managerController.login()) {
                        std::cout << "Đăng nhập thành công!\n";
                        isLogin=true;
                        // Thực hiện các chức năng quản lý
                    } else {
                        std::cout << "Đăng nhập thất bại!\n";
                    }
                }
                else {
                    std::cout << "Đăng xuất\n";
                }
                break;
            }

            case 4:
                isRunning = false;
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ!" << std::endl;
        }
        std::cout << "Nhấn phím ESC để quay lại menu chính..." << std::endl;
        char key =_getch(); // Chờ nhấn phím bất kỳ để quay lại menu chính
        while (true) {
            if (key == 27) {
                break;
            }
        }
    }

    void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
};

#endif //DISPLAYMAINCONTROLLER_H