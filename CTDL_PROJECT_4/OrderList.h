#pragma once

#include "OrderModel.h"
#include "GoodsListModel.h"

class OrderList {
private:
    std::vector<OrderModel> _orderList;
    GoodsListModel _goodList;

    void parseAndAddGoods(const std::string& orderInfo);

public:
    void readFile();
    void writeFile();
    void displayAll();
    bool checkGoodsNum(const std::vector<std::pair<std::string, int>>& codelist);
    void updateNumberFromCodeGoods(const std::vector<std::pair<std::string, int>> codelist);
    void processOrder();
};
