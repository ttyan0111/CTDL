//
// Created by giang on 11/8/24.
//
#ifndef DISPLAYMAIN_H
#define DISPLAYMAIN_H
#include "../config/Font_Color.h"
#include <iostream>
#include <vector>
#include <conio.h> // Dùng cho hàm getch() để bắt phím (trên Windows)
// #include <ncurses.h> //Dùng cho hàm getch() để bắt phím (trên Linux/MacOS)


class DisplayMain {
private:
    std::vector<std::string> options{
        
        "Hiển thị thông tin hàng hóa",
        "Tìm kiếm thông tin hàng hóa",
        "Đặt hàng",
        "Quản lý"
    };
    int selectedIndex = 0;  // Chỉ số lựa chọn hiện tại

public:

    // Hàm hiển thị menu chính
    void displayMenu() {
        while (true) {
            system("cls");  // Xóa màn hình (trên Windows)
            drawBox("===== MENU CHÍNH =====");
            for (int i = 0; i < options.size(); ++i) {
                if (i == selectedIndex) {
                    setColor(10, 0); // Màu chữ xanh lá cho lựa chọn hiện tại
                    std::cout << "> " << options[i] << " <" << std::endl;  // Hiển thị lựa chọn hiện tại
                    setColor(7, 0); // Trở về màu mặc định sau khi hiển thị
                }
                else {
                    setColor(7, 0); // Màu chữ trắng cho các lựa chọn khác
                    std::cout << "  " << options[i] << std::endl;  // Hiển thị lựa chọn không được chọn
                }
            }

            char key = _getch();  // Bắt phím nhấn  
            if (key == 72) {  // Phím mũi tên lên
                if (selectedIndex > 0) {
                    selectedIndex--;
                }
            }
            else if (key == 80) {  // Phím mũi tên xuống
                if (selectedIndex < options.size() - 1) {
                    selectedIndex++;
                }
            }
            else if (key == 13) {  // Phím Enter
                handleSelection();  // Xử lý lựa chọn
            }
        }
    }

    void drawBox(const std::string& text) {
        // Tính toán chiều dài của văn bản
        int length = text.length();

        // Vẽ dòng trên cùng
        setColor(6, 0);
        std::cout << "+" << std::string(length + 2, '*') << "+" << std::endl;

        // Vẽ dòng chứa văn bản
        std::cout << "*  ";
        setColor(2,0);
        std::cout<< text;
        setColor(6, 0);
        std::cout << " *" << std::endl;

        // Vẽ dòng dưới cùng
        std::cout << "+" << std::string(length + 2, '*') << "+" << std::endl;
        setColor(7, 0);
    }

    // Hàm xử lý khi chọn một mục trong menu
    void handleSelection() {
        system("cls");  // Xóa màn hình (trên Windows)
        switch (selectedIndex) {
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
        _getch();  // Chờ nhấn phím bất kỳ để quay lại menu chính
    }
};

#endif // DISPLAYMAIN_H