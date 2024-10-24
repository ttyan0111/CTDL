﻿//
// Created by giang on 11/8/24.
//
#ifndef DISPLAYMAIN_H
#define DISPLAYMAIN_H
#include "../config/Font_Color.h"
#include <iostream>
#include <vector>
#include <conio.h> // Dùng cho hàm getch() để bắt phím (trên Windows)

#include "Display.h"
// #include <ncurses.h> //Dùng cho hàm getch() để bắt phím (trên Linux/MacOS)

void drawBox(const std::string &text) {
    // Tính toán chiều dài của văn bản
    int length = text.length();

    // Vẽ dòng trên cùng

    setColor(6, 0);
    std::cout << "+" << std::string(length + 2, '*') << "+" << std::endl;

    // Vẽ dòng chứa văn bản
    std::cout << "*  ";
    setColor(2, 0);
    std::cout << text;
    setColor(6, 0);
    std::cout << " *" << std::endl;

    // Vẽ dòng dưới cùng
    std::cout << "+" << std::string(length + 2, '*') << "+" << std::endl;
    setColor(7, 0);
}

void display(std::vector<std::string> option, int &selected, std::string title) {
    while (true) {
        system("cls"); // Xóa màn hình (trên Windows)
        drawBox("=====" + title + "=====");
        for (int i = 0; i < option.size(); ++i) {
            if (i == selected) {
                setColor(10, 0); // Màu chữ xanh lá cho lựa chọn hiện tại
                std::cout << "> " << option[i] << " <" << std::endl; // Hiển thị lựa chọn hiện tại
                setColor(7, 0); // Trở về màu mặc định sau khi hiển thị
            } else {
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
        } else if (key == 80) {
            // Phím mũi tên xuống
            if (selected < option.size() - 1) {
                selected++;
            }
        } else if (key == 13) {
            break;
        }
    }
}


class Display {
private:
    std::vector<std::string> options{

        "Hiển thị thông tin hàng hóa",
        "Tìm kiếm thông tin hàng hóa",
        "Đặt hàng",
        "Quản lý"
    };
    std::vector<std::string> optionsManage{
        "Xử lý đơn hàng",
        "Quản lý hàng hóa",
        "Về màn hình chính"
    };
    std::vector<std::string> optionsManageGoods{
        "Thêm hàng hóa",
        "Xóa hàng hóa",
        "Cập nhật số lượng hàng",
        "Về màn hình chính"
    };
    int selectedIndex = 0; // Chỉ số lựa chọn hiện tại
    int selectedManage = 0;
    int selectedManageGoods = 0;
public:
    // Hàm hiển thị menu chính
    void displayMenu() {
        display(options, selectedIndex, "MENU CHÍNH");
    }
    void displayManager() {
        display(optionsManage, selectedManage, "MENU QUẢN LÝ");
    }
    void displayManagerGoods() {
        display(optionsManageGoods, selectedManageGoods, "QUẢN LÝ HÀNG HÓA");
    }
    int getSelectedIndex() const{ return selectedIndex; }
    int getSelectedManage() const{ return selectedManage; }
    int getSelectedManageGoods() const{ return selectedManageGoods; }
};


#endif // DISPLAYMAIN_H
