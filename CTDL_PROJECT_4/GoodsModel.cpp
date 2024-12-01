#include "GoodsModel.h"
#include <utility>


// Constructor mặc định
GoodsModel::GoodsModel() = default;

// Constructor đầy đủ
GoodsModel::GoodsModel(std::string product_code, std::string product_name, std::string place_of_origin, std::string color,
    double price, DateTimeModel import_date, int quantity)
    : productCode(std::move(product_code)),
    productName(std::move(product_name)),
    placeOfOrigin(std::move(place_of_origin)),
    color(std::move(color)),
    price(price),
    importDate(import_date),
    quantity(quantity) {
    i = 2;
    }

void GoodsModel::displayInfo() const {
    std::cout << "Product Code: " << productCode << "\n"
        << "Product Name: " << productName << "\n"
        << "Place of Origin: " << placeOfOrigin << "\n"
        << "Color: " << color << "\n"
        << "Price: " << price << "\n"
        << "Import Date: ";
    importDate.display();
    std::cout << "Quantity: " << quantity << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GoodsModel& goods) {
    os << goods.productCode << ":"
        << goods.productName << ":"
        << goods.placeOfOrigin << ":"
        << goods.color << ":"
        << goods.price << ":"
        << goods.importDate << ":"
        << goods.quantity;
    return os;
}

std::istream& operator>>(std::istream& is, GoodsModel& goods) {
    while (true) {
        goToXY(28, 3);
        std::cout << "Ma(4 ki tu): ";
        is >> goods.productCode;
        if (goods.productCode.length() != 4) {
            goToXY(28, 5);
            setColor(12, 0);
            std::cout << "Ma hang phai dung 4 ki tu!";
            setColor(7, 0);
            goToXY(28, 7);
            std::cout<<"(Enter) de nhap lai, (ESC) de thoat";
            char key = _getch();
            if (key == 27) {
                return is;
            }
            if (key == 13) {
                goToXY(28, 3);
                std::cout << std::string(50, ' ');
                goToXY(28, 5);
                std::cout << std::string(50, ' '); 
                goToXY(28, 7);
                std::cout << std::string(50, ' ');
                continue;
            }
        }
        else {
            break;
        }
    }
    is.ignore();
    goToXY(28, 5);

    std::cout << "Ten san pham: ";
    std::getline(is, goods.productName);
    goToXY(28, 7);
    std::cout << "Noi san xuat: ";
    std::getline(is, goods.placeOfOrigin);
    goToXY(28, 9);
    std::cout << "Mau sac: ";
    std::getline(is, goods.color);

    while (true) {
        goToXY(28, 11);
        std::cout << "Gia: ";
        if (is >> goods.price) {
            break;
        }
        else {
            setColor(12, 0);
            goToXY(28, 13);
            std::cout << "Gia phai la so hop le!\n";
            setColor(7, 0);

            is.clear(); // Reset trạng thái lỗi
            char c;
            while (is.get(c) && c != '\n'); // Bỏ qua từng ký tự đến khi gặp '\n'
            goToXY(28, 15);
            std::cout << "(Enter) de nhap lai, (ESC) de thoat";

            char key = _getch();
            if (key == 27) {
                return is;
            }
            if (key == 13) {
                goToXY(28, 11);
                std::cout << std::string(50, ' ');
                goToXY(28, 13);
                std::cout << std::string(50, ' ');
                goToXY(28, 15);
                std::cout << std::string(50, ' ');
                continue;
            }
        }
    }
   
    is >> goods.importDate;
    goToXY(28, 15);
    std::cout << "So luong: ";
    is >> goods.quantity;

    return is;
}

void GoodsModel::saveToFile(std::ofstream& outfile) const {
    outfile << "Item Name: " << productName << "\n"
        << "Item Price: " << price << "\n"
        << "Item Quantity: " << quantity << "\n";
}

void GoodsModel::input() {
    while (true) {
        goToXY(28, 3);
        std::cout << "Ma(4 ki tu): ";
        std :: cin >> productCode;
        if (productCode.length() != 4) {
            goToXY(28, 5);
            setColor(12, 0);
            std::cout << "Ma hang phai dung 4 ki tu!";
            setColor(7, 0);
            goToXY(28, 7);
            std::cout << "(Enter) de nhap lai, (ESC) de thoat\n";

            char key = _getch();
            if (key == 27) {
                return;
            }
            if (key == 13) {
                goToXY(28, 3);
                std::cout << std::string(50, ' ');
                goToXY(28, 5);
                std::cout << std::string(50, ' ');
                goToXY(28, 7);
                std::cout << std::string(50, ' ');
                continue;
            }
        }
        else {
            break;
        }
    }
    goToXY(28, 5);
    std::cout << "So luong: ";
    std::cin >> quantity;
}

// Getters
std::string GoodsModel::getProductCode() const { return productCode; }
std::string GoodsModel::getProductName() const { return productName; }
double GoodsModel::getPrice() const { return price; }
std::string GoodsModel::getPlaceOfOrigin() const { return placeOfOrigin; }
std::string GoodsModel::getColor() const { return color; }
DateTimeModel GoodsModel::getImportDate() const { return importDate; }
int GoodsModel::getQuantity() const { return quantity; }

// Setters
void GoodsModel::setQuantity(int quantity) { this->quantity = quantity; }
void GoodsModel::setProductCode(std::string product_code) { productCode = std::move(product_code); }
void GoodsModel::setProductName(std::string product_name) { productName = std::move(product_name); }
void GoodsModel::setPrice(double price) { this->price = price; }
void GoodsModel::setPlaceOfOrigin(std::string place_of_origin) { placeOfOrigin = std::move(place_of_origin); }
void GoodsModel::setCL(std::string color) { this->color = std::move(color); }
void GoodsModel::setImportDate(DateTimeModel import_date) { importDate = import_date; }
