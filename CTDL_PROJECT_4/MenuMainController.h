#ifndef MENUMAINCONTROLLER_H
#define MENUMAINCONTROLLER_H


#include "Display.h"
#include "OrderModelService.h"
#include <iostream>
#include "ManagerGoodsService.h"
#include "MenuManagerController.h"
#include <string>
#include <conio.h>
#include "Font_Color.h"

class MenuMainController {
private:
    Display displayMain;
    OrderModelService orderModelService;
    MenuManagerController managerController;
    ManageGoodsService goodsService;
    bool isRunning;


public:
    // Hàm khởi tạo
    MenuMainController();

    // Bắt đầu chương trình menu chính
    void start();

    // Hàm xử lý khi chọn một mục trong menu
    void handleSelection();

};

#endif // MENUMAINCONTROLLER_H
