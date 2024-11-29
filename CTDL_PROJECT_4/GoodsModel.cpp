﻿#include "GoodsModel.h"
#include <utility>
#include <limits>

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
    quantity(quantity) {}

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
        std::cout << "Ma(4 ki tu): ";
        is >> goods.productCode;
        if (goods.productCode.length() != 4) {
            std::cout << "Ma hang phai dung 4 ki tu!\n";
        }
        else {
            break;
        }
    }
    is.ignore();
    std::cout << "Ten san pham: ";
    std::getline(is, goods.productName);
    std::cout << "Noi san xuat: ";
    std::getline(is, goods.placeOfOrigin);
    std::cout << "Mau sac: ";
    std::getline(is, goods.color);

    while (true) {
        std::cout << "Gia: ";
        if (is >> goods.price) {
            break;
        }
        else {
            std::cout << "Gia phai la so hop le!\n";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    is >> goods.importDate;
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
        std::cout << "Ma(4 ki tu): ";
        std::cin >> productCode;
        if (productCode.length() != 4) {
            std::cout << "Ma hang phai dung 4 ki tu!\n";
        }
        else {
            break;
        }
    }
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
void GoodsModel::setColor(std::string color) { this->color = std::move(color); }
void GoodsModel::setImportDate(DateTimeModel import_date) { importDate = import_date; }
