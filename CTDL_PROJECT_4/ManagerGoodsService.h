#ifndef GOODSLISTSERVICE_H
#define GOODSLISTSERVICE_H

#include "GoodsListModel.h"
#include <string>
#include <iostream>

class ManageGoodsService {
private:
    GoodsListModel goodsListModel;

public:
    // Constructor
    ManageGoodsService();

    // Ghi dữ liệu vào file
    void writeToFile() const;

    // Thêm hàng hóa
    void addGoods(GoodsModel& goodsModel);

    // Xóa hàng hóa
    void deleteGoods(std::string& code);

    // Cập nhật số lượng hàng
    void updateQuantityGoods();

    // Đọc dữ liệu từ file
    void readFile();

    // Hiển thị dữ liệu hàng hóa
    void showDataAsTable();

    // Tìm kiếm hàng hóa theo tên
    void find();
};

#endif // GOODSLISTSERVICE_H
