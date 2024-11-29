// Unordered_User.cpp

#include "Unordered_User.h"


// Thêm sản phẩm vào cả hai danh sách theo tên và mã
void Unordered_User::insertFromName(const std::string& key, const GoodsModel& value) {
    goodsList_Name[key] = value;
    goodsList_Code[value.getProductCode()] = value;
}

void Unordered_User::insertFromCode(const std::string& key, const GoodsModel& value) {
    goodsList_Code[key] = value;
    goodsList_Name[value.getProductName()] = value;
}

// In danh sách hàng hóa theo tên
void Unordered_User::print() const {
    for (const auto& pair : goodsList_Name) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

// Lấy sản phẩm theo tên
const GoodsModel& Unordered_User::getFromName(const std::string& key) const {
    auto it = goodsList_Name.find(key);
    if (it != goodsList_Name.end()) {
        return it->second;
    }
    throw std::runtime_error("Ten san pham '" + key + "' khong ton tai.");
}

// Lấy sản phẩm theo mã
const GoodsModel& Unordered_User::getFromCode(const std::string& key) const {
    auto it = goodsList_Code.find(key);
    if (it != goodsList_Code.end()) {
        return it->second;
    }
    throw std::runtime_error("Ma san pham '" + key + "' khong ton tai.");
}

// Kiểm tra sản phẩm theo mã
bool Unordered_User::findFromCode(const std::string& key) const {
    return goodsList_Code.find(key) != goodsList_Code.end();
}

// Xóa sản phẩm theo mã sản phẩm (key code)
void Unordered_User::removeFromCode(const std::string& key) {
    auto it = goodsList_Code.find(key);
    if (it != goodsList_Code.end()) {
        // Lấy tên sản phẩm trước khi xóa để xóa trong goodsList_Name
        std::string productName = it->second.getProductName();

        // Xóa khỏi goodsList_Code và goodsList_Name
        goodsList_Code.erase(key);
        goodsList_Name.erase(productName);

        std::cout << "Da xoa san pham voi ma: " << key << std::endl;
    }
    else {
        std::cerr << "Khong tim thay san pham voi ma: " << key << std::endl;
    }
}

// Xóa toàn bộ dữ liệu
void Unordered_User::removeAll() {
    this->goodsList_Code.clear();
    this->goodsList_Name.clear();
}

// Cập nhật số lượng theo mã sản phẩm
bool Unordered_User::updateQuantityByCode(const std::string& key, int newQuantity) {
    auto it = goodsList_Code.find(key);
    if (it != goodsList_Code.end()) {
        // Cập nhật số lượng trong goodsList_Code
        it->second = GoodsModel(
            it->second.getProductCode(),
            it->second.getProductName(),
            it->second.getPlaceOfOrigin(),
            it->second.getColor(),
            it->second.getPrice(),
            it->second.getImportDate(),
            newQuantity
        );

        // Đồng bộ cập nhật trong goodsList_Name
        std::string productName = it->second.getProductName();
        goodsList_Name[productName] = it->second;

        std::cout << "Da cap nhat so luong cho ma: " << key << " thanh " << newQuantity << std::endl;
        return true;
    }
    else {
        std::cerr << "Khong tim thay san pham voi ma: " << key << std::endl;
        return false;
    }
}

// Lấy danh sách tất cả sản phẩm
std::vector<GoodsModel> Unordered_User::getGoodsList() const {
    std::vector<GoodsModel> allGoods;
    for (const auto& pair : goodsList_Name) {
        allGoods.push_back(pair.second);
    }
    return allGoods;
}

// Lấy danh sách sản phẩm theo tên
std::unordered_map<std::string, GoodsModel> Unordered_User::getGoodsList_Name() {
    return this->goodsList_Name;
}

// Lấy số lượng sản phẩm theo mã
int Unordered_User::getNumFromCode(const std::string& code) {
    if (goodsList_Code.find(code) != goodsList_Code.end()) {
        return goodsList_Code[code].getQuantity();
    }
    return -1; // Trả về -1 nếu không tìm thấy mã sản phẩm
}
