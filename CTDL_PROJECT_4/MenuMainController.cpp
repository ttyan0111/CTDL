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
    case 1:
        std::cout << "Hien thi thong tin hang hoa" << std::endl;
        // Thêm chức năng hiển thị thông tin hàng hóa ở đây
        goodsService.showDataAsTable();
        system("pause");
        break;
    case 2:
        std::cout << "Tim kiem thong tin hang hoa" << std::endl;
        goodsService.find();
        system("pause");
        break;
    case 3:
        std::cout << "Dat hang" << std::endl;
        orderModelService.saveOrderGoodsToFile();
        system("pause");
        // Thêm chức năng đặt hàng ở đây
        break;
    case 4: {
        std::cout << "Quan ly" << std::endl;
        managerController.start();
        break;
    }
    case 5:
        isRunning = false;
        break;
    default:
        std::cout << "Lua chon khong hop le!" << std::endl;
    }
}
