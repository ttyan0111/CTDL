#ifndef GOODSLISTSERVICE_H
#define GOODSLISTSERVICE_H

#include "GoodsListModel.h"
#include <string>
#include <iostream>
#include "Font_Color.h"
#include <conio.h>
class ManageGoodsService {
private:
    GoodsListModel goodsListModel;

public:
    // Constructor
    ManageGoodsService();

    // Ghi dữ liệu vào file
    void writeToFile() const;

    // Thêm hàng hóa
    bool addGoods(GoodsModel& goodsModel);

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
    bool boolFindByCode(std::string code);
    double getPriceByCode(std::string code);

    // lấy số lượng hàng hóa của mã hàng yêu cầu.
    int getNumofGoods(std::string code);
};

#endif // GOODSLISTSERVICE_H
