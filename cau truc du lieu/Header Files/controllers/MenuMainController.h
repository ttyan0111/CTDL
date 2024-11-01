//
// Created by Yan on 10/10/2024.
//

#ifndef DISPLAYMAINCONTROLLER_H
#define DISPLAYMAINCONTROLLER_H

#include "MenuManageController.h"
#include "../view/Display.h"

class MenuMainController {
private:
    Display displayMain;
    ManagerController managerController;
    ManageGoodsService goodsService;
    bool isRunning;
public:
    // Hàm khởi tạo
    MenuMainController() : isRunning(true) {}

    void start() {
        while (isRunning) {
            displayMain.displayMenu();
            handleSelection(); // Gọi hàm xử lý lựa chọn
        }
    }

    // Hàm xử lý khi chọn một mục trong menu
    void handleSelection() {
        system("cls");
        int selection = displayMain.getSelectedIndex();
        switch (selection) {
            case 0:
                std::cout << "Hiển thị thông tin hàng hóa" << std::endl;
                // Thêm chức năng hiển thị thông tin hàng hóa ở đây
                goodsService.showDataAsTable();
                system("pause");
            case 1:
                std::cout << "Tìm kiếm thông tin hàng hóa" << std::endl;
                goodsService.find();
                system("pause");
                break;
            case 2:
                std::cout << "Đặt hàng" << std::endl;
                // Thêm chức năng đặt hàng ở đây
                break;
            case 3: {
                std::cout << "Quản lý" << std::endl;
                managerController.start();
                break;
            }
            case 4:
                isRunning = false;
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ!" << std::endl;
        }
    }

};

#endif //DISPLAYMAINCONTROLLER_H