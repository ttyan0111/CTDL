//
// Created by Yan on 13/10/2024.
//

#ifndef GOODSLISTMODEL_H
#define GOODSLISTMODEL_H

#include <string>
#include <iostream>
#include <utility>
#include <fstream>
#include "../config/Unordered_User.h"
#include "DateTimeModel.h"

class GoodsListModel {
private:
	Unordered_User user;

public:
	// Hàm thêm hàng hóa, kiểm tra mã hàng và thêm vào danh sách
	void insertGoods(const GoodsModel& goodsModel) {

		if (!user.findFromCode(goodsModel.getProductCode())) {
			try {
				user.insertFromName(goodsModel.getProductName(), goodsModel);
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Lỗi: " << e.what() << std::endl;  // Xử lý ngoại lệ
			}
		}
		else {
			std::cout << "Mã hàng đã tồn tại" << std::endl;
		}

	}

	// Hàm xóa hàng hóa theo mã
	void removeGoods(const std::string& code) {
		user.removeFromCode(code);
	}

	// Hàm cập nhật số lượng hàng hóa
	void updateQuantityGoods(const std::string& key, int quantity) {
		user.updateQuantityByCode(key, quantity);
	}

	// Hàm ghi dữ liệu vào file
	void writeToFile(const std::string& filename) const {
		std::ofstream outFile(filename, std::ios::app);


		// Kiểm tra nếu file mở thành công
		if (!outFile) {
			std::cerr << "Có lỗi xảy ra khi ghi dữ liệu vào file: " << filename << std::endl;
		}


		std::vector<GoodsModel> goodsList = user.getGoodsList();
		if (goodsList.empty()) {
			std::cerr << "Danh sách hàng hóa trống, không có gì để ghi vào file." << std::endl;
			return;
		}
		// Lặp qua từng sản phẩm trong danh sách
		for (const auto& goods : goodsList) {
			outFile << goods.getProductCode() << ":"
				<< goods.getProductName() << ":"
				<< goods.getPlaceOfOrigin() << ":"
				<< goods.getColor() << ":"
				<< goods.getPrice() << ":"
				<< goods.getImportDate() << ":"
				<< goods.getQuantity() << std::endl; // Adjust the output format as needed
		}
		outFile.close(); // Đóng file
		std::cout << "Dữ liệu đã được lưu vào file: " << filename << std::endl;
	}
};

#endif //GOODSLISTMODEL_H