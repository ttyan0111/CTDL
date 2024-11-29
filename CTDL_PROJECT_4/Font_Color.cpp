#include "Font_Color.h"

#include <iostream>

void setColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}



void centerText(const std::string& text) {
    // Lấy chiều rộng console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int padding = (width - text.length()) / 2; // Tính khoảng cách cần thêm
    std::string centeredText(padding, ' '); // Tạo chuỗi khoảng trắng
    centeredText += text; // Căn giữa
    std::cout << centeredText << std::endl; // In ra
}
void goToXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x; // Tọa độ x (cột)
    position.Y = y; // Tọa độ y (hàng)
    SetConsoleCursorPosition(hConsole, position);
}
