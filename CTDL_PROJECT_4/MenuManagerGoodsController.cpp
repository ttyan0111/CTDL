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
        std::cout << "Them hang hoa\n";
        std::cin >> goodsModel;
        goodsService.addGoods(goodsModel);
        waittingInput();
        return false;
    case 1:
        goodsService.showDataAsTable();
        std::cout << "\nXoa hang hoa\n";
        std::cout << "Nhap ma hang can xoa: ";
        std::cin >> code;
        goodsService.deleteGoods(code);
        waittingInput();
        return false;
    case 2:
        std::cout << "Cap nhat so luong hang\n";
        goodsService.updateQuantityGoods();
        waittingInput();
        return false;
    case 3:
        std::cout << "Ve man hinh chinh\n";
        return true;
    default:
        std::cout << "Lua chon khong hop le!\n";
        waittingInput();
        return false;
    }
}
