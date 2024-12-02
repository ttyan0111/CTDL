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

void Display::display(std::vector<std::string> option, int& selected, std::string title) {
   
    
    while (true) {
       
        goToXY(6, 8); // Vị trí tiêu đề
        setColor(14, 0); // Màu vàng cho tiêu đề
        std::cout << title << std::endl;

        for (int i = 1; i < option.size(); ++i) {
            goToXY(3, 12 + (i-1) * 2); // Tính vị trí Y cho từng lựa chọn
            if (i == selected) {
                setColor(10, 0); // Màu xanh lá cho lựa chọn hiện tại
                std::cout << "> " << option[i] << std::endl;
            }
            else {
                setColor(7, 0); // Màu mặc định cho các lựa chọn khác
                std::cout << "  " << option[i]  << std::endl;
            }
        }

        char key = _getch(); // Bắt phím nhấn
        if (key == 72) { // Phím mũi tên lên
            if (selected > 0) selected--;
        }
        else if (key == 80) { // Phím mũi tên xuống
            if (selected < option.size() - 1) selected++;
        }
        else if (key == 13) { // Phím Enter
            break;
        }
    }
}

// Hàm hiển thị menu chính
void Display::displayMenu() {
    system("cls");
    hienThiGiaoDienChinh();
    backGround();
    display(options, selectedIndex, "MENU CHINH");
    
}

// Hàm hiển thị menu quản lý
void Display::displayManager() {
    system("cls");
    hienThiGiaoDienChinh();
    display(optionsManage, selectedManage, "MENU QUAN LY");
}


// Hàm hiển thị menu quản lý hàng hóa
void Display::displayManagerGoods() {
    system("cls");
    hienThiGiaoDienChinh();
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
void  Display::hienThiGiaoDienChinh() {
    std::string line;
    system("chcp 65001");
    system("cls");
    std::ifstream file("../giaodien.txt");
    while (getline(file, line)) { // Đọc từng dòng từ file
        for (char c : line) { // Duyệt từng ký tự
            if (c == '&' || c == '@' || c == '%' || c == '#' || c == '*' || c == '?' || c == '/') {
                setColor(10, 10); // Màu xám (Text: xám, Nền: đen)
                std::cout << c;
            }
            else {
                setColor(7, 0); // Mặc định (Text: trắng, Nền: đen)
                std::cout << c;
            }
        }
        std::cout << std::endl; // Xuống dòng
    }
    setColor(7, 0); // Đặt lại màu mặc định khi kết thúc
    
   
}
void Display::backGround() {
    std::string line;
    int i = 1;
    std::ifstream file("../backGround.txt");
    setColor(0, 0);
    while (getline(file, line)) { // Đọc từng dòng từ file
        goToXY(26, 4 + i+1);
        for (char c : line) {
            if (c == ',' || c=='/' || c == '*' || c =='.') {
                setColor(11,11);
            }
            else {
                setColor(0, 0);
            }
            std::cout << c;
        }
        std::cout << std::endl;
        i++;
    }
    setColor(7, 0); // Đặt lại màu mặc định khi kết thúc
}
void Display::deleteBackGround() {
    for (int i = 1; i <= 26; i++) {
        goToXY(26, i);
        std::cout << std::string(102, ' ');
    }
}