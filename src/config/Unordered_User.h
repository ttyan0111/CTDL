#ifndef UNORDERED_USER_H
#define UNORDERED_USER_H

#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include "../models/GoodsModel.h"

class Unordered_User {
private:
    std::unordered_map<std::string, GoodsModel> goodsList_Name;
    std::unordered_map<std::string, GoodsModel> goodsList_Code;

public:
    // Thêm sản phẩm vào cả hai danh sách theo tên và mã
    void insertFromName(const std::string& key, const GoodsModel& value) {
        goodsList_Code[key] = value;
        goodsList_Name[value.getProductName()] = value;
    }

    void insertFromCode(const std::string& key, const GoodsModel& value) {
        goodsList_Name[key] = value;
        goodsList_Code[value.getProductCode()] = value;
    }

    // In danh sách hàng hóa theo tên
    void print() const {
        for (const auto& [key, value] : goodsList_Name) {
            std::cout << key << " : " << value << std::endl;
        }
    }

    // Lấy sản phẩm theo tên
    const GoodsModel& getFromName(const std::string& key) const {
        auto it = goodsList_Name.find(key);
        if (it != goodsList_Name.end()) {
            return it->second;
        }
        throw std::runtime_error("Tên sản phẩm '" + key + "' không tồn tại.");
    }

    // Lấy sản phẩm theo mã
    const GoodsModel& getFromCode(const std::string& key) const {
        auto it = goodsList_Code.find(key);
        if (it != goodsList_Code.end()) {
            return it->second;
        }
        throw std::runtime_error("Mã sản phẩm '" + key + "' không tồn tại.");
    }
};


#endif // UNORDERED_USER_H
