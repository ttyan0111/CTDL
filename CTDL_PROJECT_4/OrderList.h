#pragma once

#include "OrderModel.h"
#include "GoodsListModel.h"
#include "Font_Color.h"
#include <conio.h>
class OrderList {
private:
    std::vector<OrderModel> _orderList;
    GoodsListModel _goodList;
    int i;
    void parseAndAddGoods(const std::string& orderInfo);

public:
    void readFile();
    void writeFile();
    void displayAll();
    bool checkGoodsNum(const std::vector<std::pair<std::string, int>>& codelist);
    void updateNumberFromCodeGoods(const std::vector<std::pair<std::string, int>> codelist);
    void processOrder();
};
