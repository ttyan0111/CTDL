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
        goToXY(28, 17);
        setColor(12, 0);
        std::cout << "Ma hang ton tai" << std::endl;
        setColor(7, 0);
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
    std::cout << std::endl;
    goToXY(28, 20);
    std::cout << "Nhap ma hang: ";
    std::cin >> code;

    while (true) {
        goToXY(28, 22);
        std::cout << "Nhap so luong can thay doi: ";
        std::cin >> quantity;

        // Kiểm tra nếu nhập vào không phải là số nguyên
        if (std::cin.fail()) {
            std::cin.clear();  // Xóa trạng thái lỗi
            std::cin.ignore(10000, '\n');  // Bỏ qua phần nhập không hợp lệ
            goToXY(28, 24);
            setColor(12, 0);
            std::cout << "Loi: Vui long nhap so nguyen.\n";
            setColor(7, 0);
            goToXY(28, 22);
            std::cout << std::string(90, ' ');
            goToXY(28, 24);
            std::cout << std::string(90, ' ');

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
    goToXY(28, 4);
    std::cout << "Nhap ten can tim: ";
    std::string name;
    std::getline(std::cin, name);
    goodsListModel.findGoods(name);
}
bool ManageGoodsService::boolFindByCode(std::string code) {
    readFile();
    return goodsListModel.boolFindByCode(code);
}
double ManageGoodsService::getPriceByCode(std::string code) {
    GoodsModel gm =  goodsListModel.getGoodsModelFromByCode(code);
    return gm.getPrice();
}


// lấy số lượng hàng hóa của mã hàng yêu cầu.
int ManageGoodsService::getNumofGoods(std::string code)
{
    return goodsListModel.getOneGoods(code);
}