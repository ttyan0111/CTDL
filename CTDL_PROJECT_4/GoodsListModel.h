#ifndef GOODSLISTMODEL_H
#define GOODSLISTMODEL_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Unordered_User.h"
#include "DateTimeModel.h"
#include "GoodsModel.h"
class GoodsListModel {
private:
    Unordered_User user;

public:
    // Hàm thêm hàng hóa, kiểm tra mã hàng và thêm vào danh sách
    bool insertGoods(const GoodsModel& goodsModel);

    // Hiển thị dữ liệu dưới dạng bảng
    void showDataAsTable();
    void showDataAsTable(std::vector<GoodsModel>& goodslist);

    // Hàm tách chuỗi và thêm goods vào goodslist
    void parseAndAddGoods(const std::string& goodInfo);

    // Đọc dữ liệu từ file
    void readFile();

    // Hàm xóa hàng hóa theo mã
    void removeGoods(const std::string& code);

    // Hàm cập nhật số lượng hàng hóa
    bool updateQuantityGoods(const std::string& key, int quantity);

    // Hàm ghi dữ liệu vào file
    void writeToFile(const std::string& filename) const;

    // Tìm kiếm hàng hóa
    void findGoods(const std::string name);

    // Cập nhật số lượng 1 mặt hàng
    void updateOneGoods(const std::string code, const int& num);

    // Lấy số lượng của 1 mặt hàng
    int getOneGoods(const std::string& code);
};

#endif // GOODSLISTMODEL_H
