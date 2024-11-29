#pragma once
#include <iostream>
#include "OrderModel.h"

class OrderModelService {
private:
    OrderModel orderModel;
    int nextOrderNumber;

public:
    // Constructor
    OrderModelService();

    // Phương thức lưu đơn hàng vào file
    void saveOrderGoodsToFile();

    // Phương thức đọc giá trị `nextOrderNumber` từ file
    void loadNextOrderNumberFromFile();

    // Phương thức ghi giá trị `nextOrderNumber` vào file
    void saveNextOrderNumberToFile();
};
