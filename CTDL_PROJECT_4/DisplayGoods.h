#ifndef DISPLAYGOODSADD_H
#define DISPLAYGOODSADD_H

#include <iostream>
#include <string>
#include <windows.h> // For SetConsoleCursorPosition
#include <conio.h>   // For _getch()
#include <sstream>   // For std::stringstream
#include "GoodsModel.h"
#include "DateTimeModel.h"

// Set cursor position
void setCursorPosition(int x, int y);

class DisplayGoods {
private:
    std::string productCode, productName, color, origin;
    double price;
    DateTimeModel importDate;
    int quantity;
public:
    DisplayGoods();

    // Các phương thức để nhập thông tin sản phẩm
    void inputProductDetails();
    GoodsModel createGoodsModel();
};

#endif // DISPLAYGOODSADD_H
