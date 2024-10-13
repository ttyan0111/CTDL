//
// Created by Yan on 13/10/2024.
//

#ifndef GOODSLISTSERVICE_H
#define GOODSLISTSERVICE_H
#include "../models/GoodsListModel.h"
#include <string>
#include <iostream>
class ManageGoodsService {
private:
    GoodsListModel goodsListModel;

public:
    ManageGoodsService() {
        goodsListModel = GoodsListModel();
    };
    void writeToFile() const {
        goodsListModel.writeToFile("..\\fileLogin\\hanghoa.txt");
    }

    void addGoods( GoodsModel &goodsModel) {
        goodsListModel.insertGoods(goodsModel);
    }

    void deleteGoods( std::string &code) {
        goodsListModel.removeGoods(code);
    }

    void updateQuantityGoods( std::string &code, int quantity) {
        goodsListModel.updateQuantityGoods(code, quantity);
    }
};


#endif //GOODSLISTSERVICE_H
