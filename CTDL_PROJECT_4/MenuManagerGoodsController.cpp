#include "MenuManagerGoodsController.h"

void waittingInput() {
    char key;
    key = _getch();
}

// Bắt đầu quản lý
void MenuManagerGoodsController::start() {
    while (true) {
        display.displayManagerGoods();
        if (handleSelection()) {
            break;
        }
    }
}

// Xử lý lựa chọn sau khi đăng nhập thành công
bool MenuManagerGoodsController::handleSelection() {
    std::string code;
    int selection = display.getSelectedManageGoods();
    switch (selection) {
    case 1:
        std::cin >> goodsModel;
        goodsService.addGoods(goodsModel);
        std:: cout << std::endl;
        goToXY(28, 19);
        std::cout << "Them thanh cong!";
        waittingInput();
        return false;
    case 2:
        goodsService.showDataAsTable();
        std::cout << std::endl;
        goToXY(28, 20);
        std::cout << "Nhap ma hang can xoa: ";
        std::cin >> code;
        goodsService.deleteGoods(code);
        waittingInput();
        return false;
    case 3:
        goodsService.updateQuantityGoods();
        waittingInput();
        return false;
    case 4:
        return true;
    default:
        waittingInput();
        return false;
    }
}
