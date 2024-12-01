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
    
    int selection = displayMain.getSelectedIndex();
    char key;
    switch (selection) {
    case 1:
        displayMain.deleteBackGround();
        // Thêm chức năng hiển thị thông tin hàng hóa ở đây
        goodsService.showDataAsTable();
        key = _getch();
        break;
    case 2:
        displayMain.deleteBackGround();
        goToXY(28, 2);
        std::cout << "Tim kiem thong tin hang hoa" << std::endl;
        goodsService.find();
        key = _getch();
        break;
    case 3:
        while (true) {
            orderModelService.saveOrderGoodsToFile();
            displayMain.deleteBackGround();
            goToXY(28, 3);
            std::cout << "Them don hang thanh cong, (Enter) de tiep tuc (ESC) de thoat" << std::endl;
            key = _getch();
            if (key == 13) {
                continue;
            }
            else break;
        }
        // Thêm chức năng đặt hàng ở đây
        break;
    case 4: {

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
