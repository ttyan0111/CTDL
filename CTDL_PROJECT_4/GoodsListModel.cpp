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
    goToXY(28, 3);
    setColor(6, 0);
    std::cout << "Ma Hang";
    goToXY(40, 3);
    std::cout << "Ten Hang";
    goToXY(60, 3);
    std::cout << "Noi San Xuat";
    goToXY(79, 3);
    std::cout << "Mau Sac";
    goToXY(89, 3);
    std::cout << "Gia Ban";
    goToXY(100, 3);
    std::cout << "Ngay Nhap";
    goToXY(115, 3);
    std::cout << "So Luong" << "\n";
    setColor(7, 0);
    int u = 5;
    std::vector<GoodsModel> goodslist = user.getGoodsList();
    for (auto goods : goodslist) {

        goToXY(28, u);
        std::cout  << goods.getProductCode();
        goToXY(40, u);
        std::cout << goods.getProductName();
        goToXY(60, u);
        std::cout << goods.getPlaceOfOrigin();
        goToXY(79, u);
        std::cout << goods.getColor();
        goToXY(89, u);
        std::cout << goods.getPrice();
        goToXY(100, u);
        std::cout << goods.getImportDate();
        goToXY(115, u);
        std::cout << goods.getQuantity() << std::endl;
        u += 2;

    }

}

void GoodsListModel::showDataAsTable(std::vector<GoodsModel>& goodslist) {
    goToXY(28, 3);
    setColor(6, 0);
    std::cout << "Ma Hang";
    goToXY(40, 3);
    std::cout << "Ten Hang";
    goToXY(60, 3);
    std::cout << "Noi San Xuat";
    goToXY(79, 3);
    std::cout << "Mau Sac";
    goToXY(89, 3);
    std::cout << "Gia Ban";
    goToXY(100, 3);
    std::cout << "Ngay Nhap";
    goToXY(115, 3);
    std::cout << "So Luong" << "\n";
    setColor(7, 0);
    int u = 5;
    for (auto goods : goodslist) {

        goToXY(28, u);
        std::cout << goods.getProductCode();
        goToXY(40, u);
        std::cout << goods.getProductName();
        goToXY(60, u);
        std::cout << goods.getPlaceOfOrigin();
        goToXY(79, u);
        std::cout << goods.getColor();
        goToXY(89, u);
        std::cout << goods.getPrice();
        goToXY(100, u);
        std::cout << goods.getImportDate();
        goToXY(115, u);
        std::cout << goods.getQuantity() << std::endl;
        u += 2;

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

    std::ifstream reader("HangHoa.txt");
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
        std::cerr << "Loi khi doc tep: " << e.what() << std::endl;
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
       /* std::cerr << "Danh sach hang hoa trong" << std::endl;*/
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

// chuyển các kí tử hoa thành thường.
std::string GoodsListModel::to_Lower(std::string sourceString)
{
    std::string nameX = "";

    // chuyển các kí tử hoa thành thường.
    for (int i = 0; i < sourceString.size(); ++i)
    {
        if (sourceString[i] >= 65 && sourceString[i] <= 90) nameX += (sourceString[i] + 32);
        else nameX += sourceString[i];
    }

    return nameX;
}

// Tìm kiếm hàng hóa
void GoodsListModel::findGoods(const std::string name) {
    std::vector<GoodsModel> tmp;
    for (auto x : user.getGoodsList()) {
        
        std::string nameX = to_Lower(x.getProductName());
        std::string nameY = to_Lower(name);

        if (nameX == nameY) {
            tmp.push_back(x);
        }
    }
    goToXY(28, 2);
    std::cout << std::string(90, ' ');
    goToXY(28, 4);
    std::cout << std::string(90, ' ');
    showDataAsTable(tmp);
}
bool GoodsListModel ::boolFindByCode(std::string code) {
    return user.findFromCode(code);
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

GoodsModel GoodsListModel::getGoodsModelFromByCode(std::string code) {
    return user.getFromCode(code);
}