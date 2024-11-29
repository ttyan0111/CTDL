#include "ManagerGoodsService.h"
#include <limits>

// Constructor
ManageGoodsService::ManageGoodsService() {
    goodsListModel = GoodsListModel();
}

// Ghi dữ liệu vào file
void ManageGoodsService::writeToFile() const {
    goodsListModel.writeToFile("HangHoa.txt");
}

// Thêm hàng hóa
void ManageGoodsService::addGoods(GoodsModel& goodsModel) {
    readFile();
    if (goodsListModel.insertGoods(goodsModel)) {
        writeToFile();
    }
    else {
        std::cout << "Ma hang ton tai" << std::endl;
    }
}

// Xóa hàng hóa
void ManageGoodsService::deleteGoods(std::string& code) {
    goodsListModel.removeGoods(code);
    writeToFile();
}

// Cập nhật số lượng hàng
void ManageGoodsService::updateQuantityGoods() {
    readFile();
    showDataAsTable();
    std::string code;
    int quantity;
    std::cout << "\nNhap ma hang: ";
    std::cin >> code;

    while (true) {
        std::cout << "Nhap so luong can thay doi: ";
        std::cin >> quantity;

        // Kiểm tra nếu nhập vào không phải là số nguyên
        if (std::cin.fail()) {
            std::cin.clear();  // Xóa trạng thái lỗi
            std::cin.ignore(10000, '\n');  // Bỏ qua phần nhập không hợp lệ
            std::cout << "Loi: Vui long nhap so nguyen.\n";
        }
        else {
            break;  // Thoát vòng lặp nếu nhập hợp lệ
        }
    }

    if (goodsListModel.updateQuantityGoods(code, quantity)) {
        writeToFile();
    }
}

// Đọc dữ liệu từ file
void ManageGoodsService::readFile() {
    goodsListModel.readFile();
    goodsListModel.writeToFile("HangHoa.txt");
}

// Hiển thị dữ liệu hàng hóa
void ManageGoodsService::showDataAsTable() {
    readFile();
    goodsListModel.showDataAsTable();
}

// Tìm kiếm hàng hóa theo tên
void ManageGoodsService::find() {
    goodsListModel.readFile();
    std::cout << "Nhap ten can tim: ";
    std::string name;
    std::getline(std::cin, name);
    goodsListModel.findGoods(name);
}
