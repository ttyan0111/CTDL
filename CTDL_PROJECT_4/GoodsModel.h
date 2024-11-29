#ifndef GOODS_H
#define GOODS_H

#include <string>
#include <iostream>
#include <fstream>
#include "DateTimeModel.h"

class GoodsModel {
private:
    std::string productCode;
    std::string productName;
    std::string placeOfOrigin;
    std::string color;
    double price{};
    DateTimeModel importDate;
    int quantity{};

public:
    // Constructor
    GoodsModel();
    GoodsModel(std::string product_code, std::string product_name, std::string place_of_origin, std::string color,
        double price, DateTimeModel import_date, int quantity);

    // Hiển thị thông tin
    void displayInfo() const;

    // Toàn tử nhập/xuất
    friend std::ostream& operator<<(std::ostream& os, const GoodsModel& goods);
    friend std::istream& operator>>(std::istream& is, GoodsModel& goods);

    // Lưu dữ liệu vào file
    void saveToFile(std::ofstream& outfile) const;

    // Nhập dữ liệu từ bàn phím
    void input();

    // Getters và Setters
    [[nodiscard]] std::string getProductCode() const;
    [[nodiscard]] std::string getProductName() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] std::string getPlaceOfOrigin() const;
    [[nodiscard]] std::string getColor() const;
    [[nodiscard]] DateTimeModel getImportDate() const;
    int getQuantity() const;

    void setQuantity(int quantity);
    void setProductCode(std::string product_code);
    void setProductName(std::string product_name);
    void setPrice(double price);
    void setPlaceOfOrigin(std::string place_of_origin);
    void setColor(std::string color);
    void setImportDate(DateTimeModel import_date);
};

#endif // GOODS_H
