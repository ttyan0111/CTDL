//
// Created by Yan on 13/10/2024.
//

#ifndef GOODSLISTMODEL_H
#define GOODSLISTMODEL_H

#include <string>
#include <iostream>
#include <utility>
#include <fstream>
#include "../config/Unordered_User.h"
#include "DateTimeModel.h"

class GoodsListModel {
private:
    Unordered_User user;

public:
    // Hàm thêm hàng hóa, kiểm tra mã hàng và thêm vào danh sách
    void insertGoods(const GoodsModel& goodsModel) {
        if (goodsModel.getProductCode().length() != 4) {
            std::cout << "Mã hàng phải 4 ký tự" << std::endl;
        } else {
            if (!user.findFromCode(goodsModel.getProductCode())) {
                user.insertFromName(goodsModel.getProductName(), goodsModel);
            } else {
                std::cout << "Mã hàng đã tồn tại" << std::endl;
            }
        }
    }

    // Hàm xóa hàng hóa theo mã
    void removeGoods(const std::string& code) {
        user.removeFromCode(code);
    }

    // Hàm cập nhật số lượng hàng hóa
    void updateQuantityGoods(const std::string& key, int quantity) {
        user.updateQuantityByCode(key, quantity);
    }

    // Hàm ghi dữ liệu vào file
    void writeToFile(const std::string& filename) const {
        std::ofstream outFile(filename,std::ios::app);

        // Kiểm tra nếu file mở thành công
        if (!outFile) {
            std::cerr << "Không thể mở file để ghi: " << filename << std::endl;
            return;
        }

        std::vector<GoodsModel> goodsList = user.getGoodsList();
        // Lặp qua từng sản phẩm trong danh sách
        for (const auto& goods : goodsList) {
            outFile << goods.getProductCode() << ":"
               << goods.getProductName() << ":"
               << goods.getPlaceOfOrigin() << ":"
               << goods.getColor() << ":"
               << goods.getPrice() << ":"
               << goods.getImportDate() << ":"
               << goods.getQuantity() << std::endl; // Adjust the output format as needed
        }

        outFile.close(); // Đóng file
        std::cout << "Dữ liệu đã được lưu vào file: " << filename << std::endl;
    }
};

#endif //GOODSLISTMODEL_H