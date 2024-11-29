// Unordered_User.h

#ifndef UNORDERED_USER_H
#define UNORDERED_USER_H

#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include "GoodsModel.h"



#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <vector>

class Unordered_User {
private:
    std::unordered_map<std::string, GoodsModel> goodsList_Name;
    std::unordered_map<std::string, GoodsModel> goodsList_Code;

public:
    // Thêm sản phẩm vào cả hai danh sách theo tên và mã
    void insertFromName(const std::string& key, const GoodsModel& value);
    void insertFromCode(const std::string& key, const GoodsModel& value);

    // In danh sách hàng hóa theo tên
    void print() const;

    // Lấy sản phẩm theo tên
    const GoodsModel& getFromName(const std::string& key) const;

    // Lấy sản phẩm theo mã
    const GoodsModel& getFromCode(const std::string& key) const;

    // Kiểm tra sản phẩm theo mã
    bool findFromCode(const std::string& key) const;

    // Xóa sản phẩm theo mã sản phẩm (key code)
    void removeFromCode(const std::string& key);

    // xóa toàn bộ dữ liệu.
    void removeAll();

    // Cập nhật số lượng theo mã sản phẩm
    bool updateQuantityByCode(const std::string& key, int newQuantity);

    // Lấy danh sách tất cả sản phẩm
    std::vector<GoodsModel> getGoodsList() const;

    // Lấy danh sách sản phẩm theo tên
    std::unordered_map<std::string, GoodsModel> getGoodsList_Name();

    // Lấy số lượng sản phẩm theo mã
    int getNumFromCode(const std::string& code);
};

#endif // UNORDERED_USER_H
