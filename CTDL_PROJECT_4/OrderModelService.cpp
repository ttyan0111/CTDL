#include "OrderModelService.h"
#include <fstream>

// Constructor: Tải `nextOrderNumber` từ file
OrderModelService::OrderModelService() {
    loadNextOrderNumberFromFile();
}

// Lưu thông tin đơn hàng vào file
void OrderModelService::saveOrderGoodsToFile() {
    display.deleteBackGround();
    std::cin >> orderModel;  // Nhập thông tin đơn hàng từ người dùng
    orderModel.saveOrderToFile("DonHang.txt", nextOrderNumber);  // Lưu đơn hàng vào file
    nextOrderNumber++;  // Tăng `nextOrderNumber`
    saveNextOrderNumberToFile();  // Ghi `nextOrderNumber` mới vào file
}

// Đọc giá trị `nextOrderNumber` từ file
void OrderModelService::loadNextOrderNumberFromFile() {
    std::ifstream infile("NextNumber.txt");
    if (infile.is_open()) {
        infile >> nextOrderNumber;
        infile.close();
    }
    else {
        nextOrderNumber = 1;  // Nếu không thể đọc từ file, bắt đầu từ 1
        
    }
}

// Ghi giá trị `nextOrderNumber` vào file
void OrderModelService::saveNextOrderNumberToFile() {
    std::ofstream outfile("NextNumber.txt");
    if (outfile.is_open()) {
        outfile << nextOrderNumber;
        outfile.close();
    }
}
