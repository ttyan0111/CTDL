//
// Created by giang on 10/8/24.
//
#ifndef GOODS_H
#define GOODS_H
#include <string>
#include <iostream>
#include <utility>
#include "DateTimeModel.h"
#include <fstream>  // Thêm thư viện để làm việc với tệp

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
		quantity(quantity) {
	}

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

	friend std::ostream& operator<<(std::ostream& os, const GoodsModel& goods) {
		os << goods.productCode << ":"
			<< goods.productName << ":"
			<< goods.placeOfOrigin << ":"
			<< goods.color << ":"
			<< goods.price << ":"
			<< goods.importDate << ":" // Hiển thị ngày nhập
			<< goods.quantity << ":";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, GoodsModel& goods) {

		while (true) {
			std::cout << "Mã(4 kí tự): ";
			is >> goods.productCode;
			if (goods.productCode.length() != 4) {
				std::cout << "Mã hàng phải đúng 4 kí tự!\n";
			}
			else {
				break;
			}
		}
		is.ignore();
		std::cout << "Tên sản phẩm: ";
		getline(is, goods.productName);
		std::cout << "Nơi sản xuất: ";
		getline(is, goods.placeOfOrigin);
		std::cout << "Màu sắc: ";
		getline(is, goods.color);
		while (true) {
			try {
				std::cout << "Giá: ";
				std::cin >> goods.price;

				break; // Thoát vòng lặp nếu nhập thành công
			}
			catch (const std::exception& e) {
				std::cerr << "Hãy nhập theo đúng định dạng! (" << e.what() << ")" << std::endl;

				// Xóa trạng thái lỗi và xóa đầu vào không hợp lệ
				std::cin.clear(); // Xóa trạng thái lỗi
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa dòng nhập
			}
		}

		is >> goods.importDate;
		std::cout << "Số lượng: ";
		is >> goods.quantity;

		return is;
	}


	[[nodiscard]] std::string getProductCode() const { return this->productCode; }
	[[nodiscard]] std::string getProductName() const { return this->productName; }
	[[nodiscard]] double getPrice() const { return this->price; }
	[[nodiscard]] std::string getPlaceOfOrigin() const { return this->placeOfOrigin; }
	[[nodiscard]] std::string getColor() const { return this->color; }
	[[nodiscard]] DateTimeModel getImportDate() const { return this->importDate; }
	int getQuantity() const { return this->quantity; }
	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
	void setProductCode(std::string product_code) { this->productCode = std::move(product_code); }
	void setProductName(std::string product_name) { this->productName = std::move(product_name); }
	void setPrice(double price) { this->price = price; }
	void setPlaceOfOrigin(std::string place_of_origin) { this->placeOfOrigin = std::move(place_of_origin); }
	void setColor(std::string color) { this->color = std::move(color); }
	void setImportDate(DateTimeModel import_date) { this->importDate = import_date; }
};


#endif //GOODS_H
