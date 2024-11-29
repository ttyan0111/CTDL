#include "GoodsListModel.h"

// Hàm thêm hàng hóa, kiểm tra mã hàng và thêm vào danh sách
bool GoodsListModel::insertGoods(const GoodsModel& goodsModel) {
    if (!user.findFromCode(goodsModel.getProductCode())) {
        try {
            user.insertFromName(goodsModel.getProductName(), goodsModel);
            return true;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Lỗi: " << e.what() << std::endl;
            return false;
        }
    }
    return false;
}

// Hiển thị dữ liệu dưới dạng bảng
void GoodsListModel::showDataAsTable() {
    std::cout << std::left << std::setw(9) << "Ma Hang"
        << std::setw(10) << "Ten Hang"
        << std::setw(14) << "Noi San Xuat"
        << std::setw(9) << "Mau Sac"
        << std::setw(10) << "Gia Ban"
        << std::setw(16) << "Ngay Nhap Khoa"
        << std::setw(10) << "So Luong" << "\n";

    std::vector<GoodsModel> goodslist = user.getGoodsList();
    for (auto goods : goodslist) {
        std::cout << std::left << std::setw(9) << goods.getProductCode()
            << std::setw(10) << goods.getProductName()
            << std::setw(14) << goods.getPlaceOfOrigin()
            << std::setw(9) << goods.getColor()
            << std::setw(10) << goods.getPrice()
            << std::setw(16) << goods.getImportDate()
            << std::setw(10) << goods.getQuantity() << std::endl;
    }
}

void GoodsListModel::showDataAsTable(std::vector<GoodsModel>& goodslist) {
    std::cout << std::left << std::setw(9) << "Ma Hang"
        << std::setw(10) << "Ten Hang"
        << std::setw(14) << "Noi San Xuat"
        << std::setw(9) << "Mau Sac"
        << std::setw(10) << "Gia Ban"
        << std::setw(16) << "Ngay Nhap Khoa"
        << std::setw(10) << "So Luong" << "\n";
    for (auto goods : goodslist) {
        std::cout << std::left << std::setw(9) << goods.getProductCode()
            << std::setw(10) << goods.getProductName()
            << std::setw(14) << goods.getPlaceOfOrigin()
            << std::setw(9) << goods.getColor()
            << std::setw(10) << goods.getPrice()
            << std::setw(16) << goods.getImportDate()
            << std::setw(10) << goods.getQuantity() << std::endl;
    }
}

// Hàm tách chuỗi và thêm goods vào goodslist
void GoodsListModel::parseAndAddGoods(const std::string& goodInfo) {
    std::string str[7];
    int pos1 = 0, pos2;

    for (int i = 0; i < 7; ++i) {
        pos2 = goodInfo.find(':', pos1);
        str[i] = goodInfo.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
    }

    int intDay = 1, intMonth = 1, intYear = 2000;
    pos1 = 0;
    pos2 = str[5].find('/', pos1);
    intDay = stoi(str[5].substr(pos1, pos2 - pos1));
    pos1 = pos2 + 1;
    pos2 = str[5].find('/', pos1);
    intMonth = stoi(str[5].substr(pos1, pos2 - pos1));
    pos1 = pos2 + 1;
    intYear = stoi(str[5].substr(pos1, pos2 - pos1));

    GoodsModel goods(str[0], str[1], str[2], str[3], stod(str[4]),
        DateTimeModel(intDay, intMonth, intYear), stoi(str[6]));
    insertGoods(goods);
}

// Đọc dữ liệu từ file
void GoodsListModel::readFile() {
    if (user.getGoodsList().size() > 0) {
        user.removeAll();
    }

    std::ifstream reader("Resource Files\\HangHoa.txt");
    if (!reader) {
        std::cerr << "Khong the mo tep" << std::endl;
        return;
    }

    try {
        std::string m_strLine;
        while (std::getline(reader, m_strLine)) {
            parseAndAddGoods(m_strLine);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Lỗi khi đọc tệp: " << e.what() << std::endl;
    }
    reader.close();
}

// Hàm xóa hàng hóa theo mã
void GoodsListModel::removeGoods(const std::string& code) {
    user.removeFromCode(code);
}

// Hàm cập nhật số lượng hàng hóa
bool GoodsListModel::updateQuantityGoods(const std::string& key, int quantity) {
    return user.updateQuantityByCode(key, quantity);
}

// Hàm ghi dữ liệu vào file
void GoodsListModel::writeToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::trunc);
    if (!outFile) {
        std::cerr << "Co loi xay ra khi ghi du lieu vao file: " << filename << std::endl;
        return;
    }

    std::vector<GoodsModel> goodsList = user.getGoodsList();
    if (goodsList.empty()) {
        std::cerr << "Danh sach hang hoa trong, khong co gi để ghi vao file." << std::endl;
        return;
    }

    for (const auto& goods : goodsList) {
        outFile << goods.getProductCode() << ":"
            << goods.getProductName() << ":"
            << goods.getPlaceOfOrigin() << ":"
            << goods.getColor() << ":"
            << goods.getPrice() << ":"
            << goods.getImportDate() << ":"
            << goods.getQuantity() << std::endl;
    }
    outFile.close();
}

// Tìm kiếm hàng hóa
void GoodsListModel::findGoods(const std::string name) {
    std::vector<GoodsModel> tmp;
    for (auto x : user.getGoodsList()) {
        if (x.getProductName() == name) {
            tmp.push_back(x);
        }
    }
    showDataAsTable(tmp);
}

// Cập nhật số lượng 1 mặt hàng
void GoodsListModel::updateOneGoods(const std::string code, const int& num) {
    int newQuantity = getOneGoods(code) - num;
    if (newQuantity >= 0) user.updateQuantityByCode(code, newQuantity);
}

// Lấy số lượng của 1 mặt hàng
int GoodsListModel::getOneGoods(const std::string& code) {
    return user.getNumFromCode(code);
}
