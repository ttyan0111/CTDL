#ifndef UNORDERED_USER_H
#define UNORDERED_USER_H

#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include "../models/GoodsModel.h"
#include <WinUser.h>

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
    bool findFromCode(const std::string& key) const {
        auto it = goodsList_Code.find(key);
        if (it != goodsList_Code.end()) {
            return true;
        }
        return false;
    }
    // Xóa sản phẩm theo mã sản phẩm (key code)
    void removeFromCode(const std::string& key) {
        auto it = goodsList_Code.find(key);
        if (it != goodsList_Code.end()) {
            // Lấy tên sản phẩm trước khi xóa để xóa trong goodsList_Name
            std::string productName = it->second.getProductName();

            // Xóa khỏi goodsList_Code và goodsList_Name
            goodsList_Code.erase(it);
            goodsList_Name.erase(productName);

            std::cout << "Đã xóa sản phẩm với mã: " << key << std::endl;
        } else {
            std::cerr << "Không tìm thấy sản phẩm với mã: " << key << std::endl;
        }
    }
    void updateQuantityByCode(const std::string& key, int newQuantity) {
        auto it = goodsList_Code.find(key);
        if (it != goodsList_Code.end()) {
            // Cập nhật số lượng trong goodsList_Code
            it->second = GoodsModel(
                it->second.getProductCode(),
                it->second.getProductName(),
                it->second.getPlaceOfOrigin(),
                it->second.getColor(),
                it->second.getPrice(),
                it->second.getImportDate(),
                newQuantity
            );

            // Đồng bộ cập nhật trong goodsList_Name
            std::string productName = it->second.getProductName();
            goodsList_Name[productName] = it->second;

            std::cout << "Đã cập nhật số lượng cho mã: " << key << " thành " << newQuantity << std::endl;
        } else {
            std::cerr << "Không tìm thấy sản phẩm với mã: " << key << std::endl;
        }
    }
    std::vector<GoodsModel> getGoodsList() const {
        std::vector<GoodsModel> allGoods;
        for (const auto& [key, value] : goodsList_Name) {
            allGoods.push_back(value);
        }
        return allGoods;
    }
};


#endif // UNORDERED_USER_H
