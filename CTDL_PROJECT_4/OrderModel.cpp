#include "OrderModel.h"
#include <iostream>
#include <limits>

// Constructor mặc định
OrderModel::OrderModel() : totalPrice(0.0) {}

// Constructor đầy đủ
OrderModel::OrderModel(int orderNumber, std::vector<std::pair<std::string, int>> listGoods, double totalPrice,
    std::string customerName, std::string customerAddress, std::string customerPhone,
    DateTimeModel orderDate)
    : orderNumber(orderNumber),
    listGoods(std::move(listGoods)),
    totalPrice(totalPrice),
    customerName(std::move(customerName)),
    customerAddress(std::move(customerAddress)),
    customerPhone(std::move(customerPhone)),
    orderDate(std::move(orderDate)) {}

// Getters
int OrderModel::getOrderNumber() const { return orderNumber; }
std::vector<std::pair<std::string, int>> OrderModel::getListGoods() const { return listGoods; }
double OrderModel::getTotalPrice() const { return totalPrice; }
std::string OrderModel::getCustomerName() const { return customerName; }
std::string OrderModel::getCustomerAddress() const { return customerAddress; }
std::string OrderModel::getCustomerPhone() const { return customerPhone; }
DateTimeModel OrderModel::getOrderDate() const { return orderDate; }

// Hiển thị thông tin đơn hàng
void OrderModel::display() const {
    std::cout << orderNumber << ":"
        << customerName << ":"
        << customerAddress << ":"
        << customerPhone << ":"
        << orderDate << ":";

    for (const auto& item : listGoods) {
        std::cout << item.first << ":" << item.second << ":";
    }

    std::cout << totalPrice << std::endl;
}

// Nhập thông tin khách hàng
void OrderModel::inputCustomerInfo(std::istream& in) {
    std::cout << "Nhap ten khach hang: ";
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    std::getline(in, customerName);

    std::cout << "Nhap dia chi khach hang: ";
    std::getline(in, customerAddress);

    std::cout << "Nhap so dien thoai khach hang: ";
    std::getline(in, customerPhone);
}

// Nhập danh sách hàng hóa
void OrderModel::inputGoodsList(std::istream& in) {
    int itemCount;
    std::cout << "Nhap so luong mat hang: ";
    while (!(in >> itemCount)) {
        std::cout << "Loi: Vui long nhap so nguyen.\nNhap lai so luong mat hang: ";
        in.clear();
        in.ignore(10000, '\n');
    }
    in.ignore();

    listGoods.clear();
    for (int i = 0; i < itemCount; ++i) {
        std::cout << "Nhap thong tin mat hang thu " << (i + 1) << ":\n";
        std::string code;
        int quantity;
        std::cout << "Nhap ma hang: ";
        in >> code;
        std::cout << "Nhap so luong: ";
        while (!(in >> quantity)) {
            std::cout << "Loi: Vui long nhap so nguyen.\nNhap lai so luong: ";
            in.clear();
            in.ignore(10000, '\n');
        }
        listGoods.push_back({ code, quantity });
    }
}

// Quá tải toán tử >>
std::istream& operator>>(std::istream& in, OrderModel& order) {
    order.inputCustomerInfo(in);
    order.inputGoodsList(in);
    return in;
}

// Lưu đơn hàng vào file
void OrderModel::saveOrderToFile(const std::string& filename, int orderNumber) {
    std::ofstream outfile(filename, std::ios::app);  // Mở file ở chế độ append
    if (outfile.is_open()) {
        orderDate.setToCurrentDate();
        outfile << orderNumber << ":"
            << customerName << ":"
            << customerAddress << ":"
            << customerPhone << ":"
            << orderDate.toString() << ":";

        for (const auto& item : listGoods) {
            outfile << item.first << ":" << item.second << ":";
        }

        outfile << totalPrice << "\n";  // Thêm dòng trống giữa các đơn hàng
    }
    else {
        std::cerr << "Loi: Khong the mo file de ghi." << std::endl;
    }
}
