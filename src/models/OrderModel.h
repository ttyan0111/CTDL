//
// Created by giang on 11/8/24.
//
#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include "GoodsModel.h"
#include "DateTimeModel.h"

class OrderModel {
private:
    int orderNumber;  // Số thứ tự đơn hàng
    std::vector<GoodsModel> items;  // Danh sách mã hàng
    int quantity;  // Tổng số lượng hàng
    double totalPrice;  // Tổng tiền
    std::string customerName;  // Tên khách hàng
    std::string customerAddress;  // Địa chỉ khách hàng
    std::string customerPhone;  // Số điện thoại khách hàng
    DateTimeModel orderDate;  // Ngày đặt hàng

public:
    // Constructor
    OrderModel() = default;
    OrderModel(int order_number, std::vector<GoodsModel> items, int quantity, double total_price,
        std::string customer_name, std::string customer_address, std::string customer_phone,
        DateTimeModel order_date)
        : orderNumber(order_number),
        items(std::move(items)),
        quantity(quantity),
        totalPrice(total_price),
        customerName(std::move(customer_name)),
        customerAddress(std::move(customer_address)),
        customerPhone(std::move(customer_phone)),
        orderDate(order_date) {}

    // Phương thức hiển thị thông tin đơn hàng
    void displayOrderInfo() const {
        std::cout << "Order Number: " << orderNumber << "\n"
            << "Customer Name: " << customerName << "\n"
            << "Customer Address: " << customerAddress << "\n"
            << "Customer Phone: " << customerPhone << "\n"
            << "Order Date: ";
        orderDate.display();  // Hiển thị ngày đặt hàng
        std::cout << "Total Quantity: " << quantity << "\n"
            << "Total Price: " << totalPrice << "\n";
        std::cout << "Items:\n";
        for (const auto& item : items) {
            item.displayInfo();  // Hiển thị thông tin từng mã hàng
        }
    }

    // Getter và Setter cho các thuộc tính nếu cần thiết
};

#endif // ORDER_H