#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>
#include "GoodsModel.h"
#include "DateTimeModel.h"

class OrderModel {
private:
    int orderNumber;  // Số thứ tự đơn hàng
    std::vector<std::pair<std::string, int>> listGoods;  // Danh sách mã hàng và số lượng
    double totalPrice;  // Tổng tiền
    std::string customerName;  // Tên khách hàng
    std::string customerAddress;  // Địa chỉ khách hàng
    std::string customerPhone;  // Số điện thoại khách hàng
    DateTimeModel orderDate;  // Ngày đặt hàng

public:
    // Constructors
    OrderModel();
    OrderModel(int orderNumber, std::vector<std::pair<std::string, int>> listGoods, double totalPrice,
        std::string customerName, std::string customerAddress, std::string customerPhone,
        DateTimeModel orderDate);

    // Getters
    int getOrderNumber() const;
    std::vector<std::pair<std::string, int>> getListGoods() const;
    double getTotalPrice() const;
    std::string getCustomerName() const;
    std::string getCustomerAddress() const;
    std::string getCustomerPhone() const;
    DateTimeModel getOrderDate() const;

    // Hiển thị đơn hàng
    void display() const;

    // Nhập thông tin khách hàng
    void inputCustomerInfo(std::istream& in);

    // Nhập danh sách hàng hóa
    void inputGoodsList(std::istream& in);

    // Quá tải toán tử >>
    friend std::istream& operator>>(std::istream& in, OrderModel& order);

    // Lưu đơn hàng vào file
    void saveOrderToFile(const std::string& filename, int orderNumber);
};

#endif // ORDER_H
