#include "MenuMainController.h"

MenuMainController::MenuMainController() : isRunning(true) {}

void MenuMainController::start() {
    while (isRunning) {
        displayMain.displayMenu();
        handleSelection(); // Gọi hàm xử lý lựa chọn
    }
}

// Hàm xử lý khi chọn một mục trong menu
void MenuMainController::handleSelection() {
    system("cls");
    int selection = displayMain.getSelectedIndex();
    switch (selection) {
    case 0:
        std::cout << "Hiển thị thông tin hàng hóa" << std::endl;
        // Thêm chức năng hiển thị thông tin hàng hóa ở đây
        goodsService.showDataAsTable();
        system("pause");
        break;
    case 1:
        std::cout << "Tìm kiếm thông tin hàng hóa" << std::endl;
        goodsService.find();
        system("pause");
        break;
    case 2:
        std::cout << "Đặt hàng" << std::endl;
        orderModelService.saveOrderGoodsToFile();
        system("pause");
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
