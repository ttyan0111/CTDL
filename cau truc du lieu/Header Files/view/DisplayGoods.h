//
// Created by Yan on 13/10/2024.
//

//
// Created by Yan on 13/10/2024.
//

#ifndef DISPLAYGOODSADD_H
#define DISPLAYGOODSADD_H

#include <iostream>
#include <string>
#include <windows.h> // For SetConsoleCursorPosition
#include <conio.h>   // For _getch()
#include <sstream>   // For std::stringstream
#include "../models/GoodsModel.h"


// Set cursor position
void setCursorPosition(int x, int y) {
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class DisplayGoods {
private:
    std::string productCode, productName, color, origin, price, importDate;
    int quantity;
public:
    DisplayGoods();

};


#endif // DISPLAYGOODSADD_H
