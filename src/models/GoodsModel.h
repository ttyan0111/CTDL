//
// Created by giang on 10/8/24.
//
#ifndef GOODS_H
#define GOODS_H
#include <string>
#include <iostream>
#include <utility>
#include "DateTimeModel.h"
// Khai báo trong lớp Goods
class GoodsModel {
private:
    std::string productCode;
    std::string productName;
    std::string placeOfOrigin;
    std::string color;
    double price;
    DateTimeModel importDate; // Sử dụng lớp DateTime
    int quantity;

public:
    // Constructor
    GoodsModel() = default;
    GoodsModel(std::string product_code, std::string product_name, std::string place_of_origin, std::string color,
          double price, DateTimeModel import_date, int quantity)
        : productCode(std::move(product_code)),
          productName(std::move(product_name)),
          placeOfOrigin(std::move(place_of_origin)),
          color(std::move(color)),
          price(price),
          importDate(import_date),
          quantity(quantity) {}

    void displayInfo() const {
        std::cout << "Product Code: " << productCode << "\n"
                  << "Product Name: " << productName << "\n"
                  << "Place of Origin: " << placeOfOrigin << "\n"
                  << "Color: " << color << "\n"
                  << "Price: " << price << "\n"
                  << "Import Date: ";
        importDate.display(); // Hiển thị ngày nhập
        std::cout << "Quantity: " << quantity << std::endl;
    }
    [[nodiscard]] std::string getProductCode() const {return this->productCode;}
    [[nodiscard]] std::string getProductName() const {return this->productName;}
    [[nodiscard]] double getPrice() const{return this->price;}
    friend std::ostream& operator<<(std::ostream& os, const GoodsModel& goods) {
        os << "Product Code: " << goods.productCode << "\n"
           << "Product Name: " << goods.productName << "\n"
           << "Place of Origin: " << goods.placeOfOrigin << "\n"
           << "Color: " << goods.color << "\n"
           << "Price: " << goods.price << "\n"
           << "Import Date: ";
        goods.importDate.display();  // Hiển thị ngày nhập
        os << "Quantity: " << goods.quantity << "\n";
        return os;
    }

};



#endif //GOODS_H