#include "Font_Color.h"
#include <windows.h>
#include <iostream>

void setColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}

void setFontSize(int fontSize) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
    cfi.dwFontSize.Y = fontSize; // Thay đổi kích thước phông chữ
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
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
