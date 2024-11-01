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
        goodsListModel.writeToFile("Resource Files\\HangHoa.txt");
    }

    void addGoods(GoodsModel& goodsModel) {
        readFile();
        if (goodsListModel.insertGoods(goodsModel)) {
            writeToFile();
        }
        else {
            std::cout << "Ma hang ton tai" << std::endl;
        }
    }

    void deleteGoods( std::string &code) {
        goodsListModel.removeGoods(code);
        writeToFile();
    }

    void updateQuantityGoods( std::string &code, int quantity) {
        goodsListModel.updateQuantityGoods(code, quantity);
    }
    void readFile() {
        this->goodsListModel.readFile();
        goodsListModel.writeToFile("Resource Files\\HangHoa.txt");
    }
    void showDataAsTable() {
        readFile();
        this->goodsListModel.showDataAsTable();
    }
    void find() {
        goodsListModel.readFile();
        std::cout << "Nhap ten can tim: ";
        std::string name;
        getline(std::cin, name);
        this->goodsListModel.findGoods(name);
    }
};


#endif //GOODSLISTSERVICE_H
