//
// Created by giang on 10/8/24.
//
#ifndef GOODS_H
#define GOODS_H
#include <string>
#include <iostream>
#include <utility>
#include "DateTime.h"
// Khai báo trong lớp Goods
class Goods {
private:
    std::string productCode;
    std::string productName;
    std::string placeOfOrigin;
    std::string color;
    double price;
    DateTime importDate; // Sử dụng lớp DateTime
    int quantity;

public:
    // Constructor
    Goods() = default;
    Goods(std::string product_code, std::string product_name, std::string place_of_origin, std::string color,
          double price, DateTime import_date, int quantity)
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
};


#endif //GOODS_H