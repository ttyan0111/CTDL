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
#include <iomanip> // sử dụng setWW() căn độ rộng cho từng cột table.


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
    // hiển thị dữ liệu dưới dạng bảng.
    void showDataAsTable() {
        readFile();
        // hiển thị tên các cột trong của bảng.
        std::cout << std::left << std::setw(9) << "Ma Hang"
            << std::left << std::setw(10) << "Ten Hang"
            << std::left << std::setw(14) << "Noi San Xuat"
            << std::left << std::setw(9) << "Mau Sac"
            << std::left << std::setw(10) << "Gia Ban"
            << std::left << std::setw(16) << "Ngay Nhap Khoa"
            << std::left << std::setw(10) << "So Luong" << "\n";

        // coppy danh sách goodList dang unordered_map sang dạng goodslist vector.
        // để dể in lên console.
        std::vector<GoodsModel> goodslist = user.getGoodsList();

        // hiển thị dử liệu của từng thông tin của goods lên cột tương ứng.
        for (auto goods : goodslist) {
            std::cout << std::left << std::setw(9) << goods.getProductCode()
                << std::left << std::setw(10) << goods.getProductName()
                << std::left << std::setw(14) << goods.getPlaceOfOrigin()
                << std::left << std::setw(9) << goods.getColor()
                << std::left << std::setw(10) << goods.getPrice()
                << std::left << std::setw(16) << goods.getImportDate()
                << std::left << std::setw(10) << goods.getQuantity() << std::endl;
        }

    }

    // hàm tách chuỗi và thêm goods vào goodslist.
    void parseAndAddGoods(const std::string& goodInfo) {
        std::string str[7];
        int pos1 = 0;
        int pos2;

        // tách chuỗi theo ':'.
        for (int i = 0; i < 7; ++i) {
            pos2 = goodInfo.find(':', pos1);
            str[i] = goodInfo.substr(pos1, pos2 - pos1);
            pos1 = pos2 + 1;
        }

        // lấy ngày tháng năm từ chuỗi str[5].
        int intDay = 1, intMonth = 1, intYear = 2000;

        pos1 = 0;
        pos2 = str[5].find('/', pos1);
        intDay = stoi(str[5].substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = str[5].find('/', pos1);
        intMonth = stoi(str[5].substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        intYear = stoi(str[5].substr(pos1, pos2 - pos1));

        // tạo goods và thêm data vào goodslist.
        GoodsModel goods(str[0], str[1], str[2], str[3], stod(str[4]), DateTimeModel(intDay, intMonth, intYear), stoi(str[6]));
        this->insertGoods(goods);
    }

    // đọc dữ liệu từ file HangHoa.txt.
    void readFile() {

        if (this->user.getGoodsList().size() > 0) {
            this->user.removeAll();
        }
        std::ifstream reader("Resource Files\\HangHoa.txt");

        if (!reader) {
            std::cerr << "Khong the mo tep" << std::endl;
        }

        try {
            std::string m_strLine; // Lưu từng dòng của tệp.
            while (std::getline(reader, m_strLine)) {
                this->parseAndAddGoods(m_strLine);
            }
        }
        catch (const std::exception& e) { // Bắt lỗi chuẩn từ chuẩn C++
            std::cerr << "Lỗi khi đọc tệp: " << e.what() << std::endl;
        }
        reader.close(); // Đảm bảo tệp được đóng sau khi đọc.
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