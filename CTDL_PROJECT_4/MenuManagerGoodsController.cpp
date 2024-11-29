#include "MenuManagerGoodsController.h"

void waittingInput() {
    std::cout << "\nHay nhan enter de tiep tuc!";
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
    system("cls");
    int selection = display.getSelectedManageGoods();
    switch (selection) {
    case 0:
        std::cout << "Thêm hàng hóa\n";
        std::cin >> goodsModel;
        goodsService.addGoods(goodsModel);
        waittingInput();
        return false;
    case 1:
        goodsService.showDataAsTable();
        std::cout << "\nXóa hàng hóa\n";
        std::cout << "Nhap ma hang can xoa: ";
        std::cin >> code;
        goodsService.deleteGoods(code);
        waittingInput();
        return false;
    case 2:
        std::cout << "Cập nhật số lượng hàng\n";
        goodsService.updateQuantityGoods();
        waittingInput();
        return false;
    case 3:
        std::cout << "Về màn hình chính\n";
        return true;
    default:
        std::cout << "Lựa chọn không hợp lệ!\n";
        waittingInput();
        return false;
    }
}
