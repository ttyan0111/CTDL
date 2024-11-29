#include "Display.h"

// Hàm vẽ hộp với văn bản
void Display::drawBox(const std::string& text) {
    int length = text.length();
    setColor(6, 0);
    std::cout << "+" << std::string(length + 2, '*') << "+" << std::endl;

    std::cout << "*  ";
    setColor(2, 0);
    std::cout << text;
    setColor(6, 0);
    std::cout << " *" << std::endl;

    std::cout << "+" << std::string(length + 2, '*') << "+" << std::endl;
    setColor(7, 0);
}

// Hàm hiển thị danh sách các lựa chọn
void Display::display(std::vector<std::string> option, int& selected, std::string title) {
    while (true) {
        system("cls"); // Xóa màn hình (trên Windows)
        drawBox("=====" + title + "=====");
        for (int i = 0; i < option.size(); ++i) {
            if (i == selected) {
                setColor(10, 0); // Màu chữ xanh lá cho lựa chọn hiện tại
                std::cout << "> " << option[i] << " <" << std::endl; // Hiển thị lựa chọn hiện tại
                setColor(7, 0); // Trở về màu mặc định sau khi hiển thị
            }
            else {
                setColor(7, 0); // Màu chữ trắng cho các lựa chọn khác
                std::cout << "  " << option[i] << std::endl; // Hiển thị lựa chọn không được chọn
            }
        }
        char key = _getch(); // Bắt phím nhấn
        if (key == 72) {
            // Phím mũi tên lên
            if (selected > 0) {
                selected--;
            }
        }
        else if (key == 80) {
            // Phím mũi tên xuống
            if (selected < option.size() - 1) {
                selected++;
            }
        }
        else if (key == 13) {
            break;
        }
    }
}

// Hàm hiển thị menu chính
void Display::displayMenu() {
    display(options, selectedIndex, "MENU CHINH");
}

// Hàm hiển thị menu quản lý
void Display::displayManager() {
    display(optionsManage, selectedManage, "MENU QUAN LY");
}

// Hàm hiển thị menu quản lý hàng hóa
void Display::displayManagerGoods() {
    display(optionsManageGoods, selectedManageGoods, "QUAN LY HANG HOA");
}

// Lấy chỉ số lựa chọn hiện tại
int Display::getSelectedIndex() const {
    return selectedIndex;
}

int Display::getSelectedManage() const {
    return selectedManage;
}

int Display::getSelectedManageGoods() const {
    return selectedManageGoods;
}
