//
// Created by Yan on 10/10/2024.
//

#ifndef DISPLAYMAINCONTROLLER_H
#define DISPLAYMAINCONTROLLER_H
#include "../view/DisplayMain.h"

class DisplayMainController {
private:
    DisplayMain displayMain;

public:
    // Hàm khởi tạo
    DisplayMainController() {
        // Bạn có thể khởi tạo một số giá trị ở đây nếu cần
    }

    void setDisplayMain(DisplayMain displayMain) {
        this->displayMain = displayMain; // Lưu trữ đối tượng DisplayMain
    }

    void start() {
        while (true) {
            displayMain.displayMenu();
            handleSelection(); // Gọi hàm xử lý lựa chọn
        }
    }

    // Hàm xử lý khi chọn một mục trong menu
    void handleSelection() {
        system("cls");  // Xóa màn hình (trên Windows)
        switch (displayMain.getSelectedIndex()) {
            case 0:
                std::cout << "Hiển thị thông tin hàng hóa" << std::endl;
            // Thêm chức năng hiển thị thông tin hàng hóa ở đây
            break;
            case 1:
                std::cout << "Tìm kiếm thông tin hàng hóa" << std::endl;
            // Thêm chức năng tìm kiếm hàng hóa ở đây
            break;
            case 2:
                std::cout << "Đặt hàng" << std::endl;
            // Thêm chức năng đặt hàng ở đây
            break;
            case 3:
                std::cout << "Quản lý" << std::endl;
            // Thêm chức năng quản lý ở đây
            break;
        }
        std::cout << "Nhấn phím bất kỳ để quay lại menu chính..." << std::endl;
        _getch(); // Chờ nhấn phím bất kỳ để quay lại menu chính
    }
};

#endif //DISPLAYMAINCONTROLLER_H
