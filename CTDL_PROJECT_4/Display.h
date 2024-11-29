#ifndef DISPLAYMAIN_H
#define DISPLAYMAIN_H

#include "Font_Color.h"
#include <iostream>
#include <vector>
#include <conio.h> // Dùng cho hàm getch() để bắt phím (trên Windows)
#include <string>
#include "Font_Color.h"
#include <fstream>
class Display {
private:
    std::vector<std::string> options{
        " ",
        "Hien thi hang hoa",
        "Tim kiem hang hoa",
        "Dat hang",
        "Quan ly"
    };
    std::vector<std::string> optionsManage{
        " ",
        "Xu ly don hang",
        "Quan ly hang hoa",
        "Ve man hinh chinh"
    };
    std::vector<std::string> optionsManageGoods{
        " ",
        "Them hang hoa",
        "Xoa hang hoa",
        "Cap nhat so luong",
        "Ve man hinh chinh"
    };
    int selectedIndex = 0; // Chỉ số lựa chọn hiện tại
    int selectedManage = 0;
    int selectedManageGoods = 0;

    // Hàm vẽ hộp với văn bản
    void drawBox(const std::string& text);

    // Hàm hiển thị danh sách các lựa chọn
    void display(std::vector<std::string> option, int& selected, std::string title);

public:
    // Hàm hiển thị menu chính
    void displayMenu();

    // Hàm hiển thị menu quản lý
    void displayManager();

    // Hàm hiển thị menu quản lý hàng hóa
    void displayManagerGoods();

    // Lấy chỉ số lựa chọn hiện tại
    int getSelectedIndex() const;
    int getSelectedManage() const;
    int getSelectedManageGoods() const;
    static void hienThiGiaoDienChinh();
    static void  backGround();
};

#endif // DISPLAYMAIN_H
