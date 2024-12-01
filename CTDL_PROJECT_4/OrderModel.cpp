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
    goToXY(28, 3);
    std::cout << "Nhap ten khach hang: ";
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    std::getline(in, customerName);
    goToXY(28, 5);
    std::cout << "Nhap dia chi khach hang: ";
    std::getline(in, customerAddress);
    goToXY(28, 7);
    std::cout << "Nhap so dien thoai khach hang: ";
    std::getline(in, customerPhone);
}

// Nhập danh sách hàng hóa
void OrderModel::inputGoodsList(std::istream& in) {
    double total = 0;
    int itemCount;
    goToXY(28, 9);
    std::cout << "Nhap so luong mat hang: ";
    while (!(in >> itemCount)) {
        goToXY(28, 9);
        std::cout << std::string(90, ' ');
        goToXY(28, 9);
        setColor(12, 0);
        std::cout << "Loi: Vui long nhap so nguyen";
        setColor(7, 0);
        goToXY(60, 9);
        std::cout << "Nhap lai so luong mat hang : "; 
        in.clear();
        in.ignore(10000, '\n');
        
    }
    in.ignore();

    listGoods.clear();
    for (int i = 0; i < itemCount; ++i) {
        goToXY(28, 13);
        std::cout << "Nhap thong tin mat hang thu " << (i + 1) << ":\n";
        std::string code;
        int quantity;
        while (true) {
            goToXY(28, 15);
            std::cout << "Nhap ma hang: ";
            in >> code;
            // Kiểm tra mã hàng hóa trong danh sách
            if (manageGoodsService.boolFindByCode(code)) {
                break;
            }
            else {
                goToXY(28, 17);
                setColor(12, 0);
                std::cout << "Ma hang khong ton tai. Enter de nhap lai ma hang!";
                char key = _getch();
                if (key == 13) {
                    setColor(7, 0);
                    goToXY(28, 15);
                    std::cout << std::string(90, ' ');
                    goToXY(28, 17);
                    std::cout << std::string(90, ' ');
                    continue;
                }
                
            }
            

        }





        goToXY(28, 17);
        std::cout << "Nhap so luong: ";
        while (!(in >> quantity)) {
            goToXY(28, 17);
            std::cout << std::string(90, ' ');
            goToXY(28, 17);
            setColor(12, 0);
            std::cout << "Loi: Vui long nhap so nguyen";
            setColor(7, 0);
            goToXY(60, 17);
            std::cout << "Nhap lai so luong : ";
            in.clear();
            in.ignore(10000, '\n');


        }
        double price = manageGoodsService.getPriceByCode(code);
        total += quantity * price;
       
        goToXY(28, 13);
        std::cout << std::string(100, ' ');
        goToXY(28, 15);
        std::cout << std::string(100, ' ');
        goToXY(28, 17);
        std::cout << std::string(100, ' ');
        listGoods.push_back({ code, quantity });

    }
    goToXY(28, 19);
    std::cout << "Tong tien cua don hang: " << total;
    totalPrice = total; // Cập nhật tổng tiền vào biến thành viên
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
