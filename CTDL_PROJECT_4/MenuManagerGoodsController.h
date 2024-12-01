#ifndef MENUMANAGEGOODSCONTROLLER_H
#define MENUMANAGEGOODSCONTROLLER_H

#include <iostream>
#include <conio.h> // Dùng cho hàm getch() để bắt phím (trên Windows)
#include "ManagerGoodsService.h"
#include "Display.h"
#include <string>

void waittingInput();  // Hàm chờ người dùng nhấn Enter

class MenuManagerGoodsController {
private:
    Display display;
    ManageGoodsService goodsService;
    GoodsModel goodsModel;
    
public:
    // Bắt đầu quản lý
    void start();

    // Xử lý lựa chọn sau khi đăng nhập thành công
    bool handleSelection();
};

#endif // MENUMANAGEGOODSCONTROLLER_H
