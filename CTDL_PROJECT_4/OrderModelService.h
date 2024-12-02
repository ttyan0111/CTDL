#pragma once
#include <iostream>
#include "OrderModel.h"
#include "Display.h"
class OrderModelService {
private:
    OrderModel orderModel;
    int nextOrderNumber;
    Display display;
public:
    // Constructor
    OrderModelService();

    // Phương thức lưu đơn hàng vào file
    bool saveOrderGoodsToFile();

    // Phương thức đọc giá trị `nextOrderNumber` từ file
    void loadNextOrderNumberFromFile();

    // Phương thức ghi giá trị `nextOrderNumber` vào file
    void saveNextOrderNumberToFile();
};
