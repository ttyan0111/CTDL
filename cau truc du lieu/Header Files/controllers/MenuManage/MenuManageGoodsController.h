//
// Created by Yan on 13/10/2024.
//

#ifndef MENUMANAGEGOODSCONTROLLER_H
#define MENUMANAGEGOODSCONTROLLER_H


#include <iostream>
#include <conio.h> // Dùng cho hàm getch() để bắt phím (trên Windows)
#include "../../service/ManageGoodsService.h"
#include "../../view/Display.h"



class MenuManagerGoodsController {
private:
    Display display;
    ManageGoodsService goodsService;
    GoodsModel goodsModel;
public:
    // Bắt đầu quản lý
    void start() {
        while (true) {
            display.displayManagerGoods();
            if (handleSelection()) {
                break;
            }
        }
    }

    // Xử lý lựa chọn sau khi đăng nhập thành công
    bool handleSelection() {
        system("cls");
        int selection = display.getSelectedManageGoods();
        switch (selection) {
            case 0:
                std::cout << "Thêm hàng hóa\n";
                std:: cin >> goodsModel;
                goodsService.addGoods(goodsModel);
                goodsService.writeToFile();
                char key;
                key = _getch();
                return false;
            case 1:
                std::cout << "Xóa hàng hóa\n";
                return false;
            case 2:
                std::cout << "Cập nhật số lượng hàng\n";
                return false;
            case 3:
                std::cout << "Về màn hình chính\n";
                return true;
            default:
                std::cout << "Lựa chọn không hợp lệ!\n";
            return false;
        }
    }
};
#endif //MENUMANAGEGOODSCONTROLLER_H
