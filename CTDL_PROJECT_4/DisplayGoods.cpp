#include "DisplayGoods.h"

void setCursorPosition(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Hàm khởi tạo mặc định
DisplayGoods::DisplayGoods() : productCode(""), productName(""), color(""), origin(""), price(), importDate(), quantity(0) {}

// Hàm nhập thông tin chi tiết sản phẩm
void DisplayGoods::inputProductDetails() {
    setCursorPosition(0, 0);
    std::cout << "Nhap ma hang: ";
    std::getline(std::cin, productCode);

    std::cout << "Nhap ten hang: ";
    std::getline(std::cin, productName);

    std::cout << "Nhap mau sac: ";
    std::getline(std::cin, color);

    std::cout << "Nhap xuat xu: ";
    std::getline(std::cin, origin);

    std::cout << "Nhap gia: ";
    std::cin >> price;

    std::cout << "Nhap ngay nhap: ";
    std::cin >> importDate;

    // Nhập số lượng với kiểm tra đầu vào hợp lệ
    while (true) {
        std::cout << "Nhap so luong: ";
        std::cin >> quantity;

        if (std::cin.fail()) {
            std::cin.clear(); // Xóa trạng thái lỗi
            std::cin.ignore(10000, '\n'); // Bỏ qua phần nhập không hợp lệ
            std::cout << "Vui long nhap so nguyen.\n";
        }
        else {
            break;
        }
    }
}

// Hàm tạo đối tượng GoodsModel từ thông tin nhập vào
GoodsModel DisplayGoods::createGoodsModel() {
    GoodsModel newGoods;
    newGoods = GoodsModel(productCode, productName, color, origin, price, importDate, quantity);
    return newGoods;
}
