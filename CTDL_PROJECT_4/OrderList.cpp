#include "OrderList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/***********************************************
 * @Description tách chuỗi và thêm order vào orderlist.
 * @Parameter chuoi can tach.
 ***********************************************/
void OrderList::parseAndAddGoods(const std::string& orderInfo) {
    std::string str[6];
    int i = 1;
    int pos1 = 0;
    int pos2;
    for (int i = 0; i < 5; ++i) {
        pos2 = orderInfo.find(':', pos1);
        str[i] = orderInfo.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
    }

    std::vector<std::pair<std::string, int>> listCodeAndNum;
    while (true) {
        std::string code;
        pos2 = orderInfo.find(':', pos1);

        if (pos2 == -1) {
            str[5] = orderInfo.substr(pos1);
            break;
        }
        code = orderInfo.substr(pos1, pos2 - pos1);

        pos1 = pos2 + 1;
        int num;
        pos2 = orderInfo.find(':', pos1);
        num = stoi(orderInfo.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;

        listCodeAndNum.push_back({ code, num });
    }

    pos1 = 0;
    pos2 = str[4].find('/', pos1);
    int day = stoi(str[4].substr(pos1, pos2 - pos1));
    pos1 = pos2 + 1;

    pos2 = str[4].find('/', pos1);
    int month = stoi(str[4].substr(pos1, pos2 - pos1));
    pos1 = pos2 + 1;

    int year = stoi(str[4].substr(pos1));

    OrderModel order = OrderModel(stoi(str[0]), listCodeAndNum, stod(str[5]), str[1], str[2], str[3],
        DateTimeModel(day, month, year));

    _orderList.push_back(order);
}

/***********************************************
 * @Description đọc dữ liệu từ file DonHang.txt
 *   và HangHoa.txt.
 ***********************************************/
void OrderList::readFile() {
    _goodList.readFile();
    if (!_orderList.empty()) {
        _orderList.clear();
    }

    std::ifstream reader("DonHang.txt");
    if (!reader) {
        std::cerr << "Khong the mo tep" << std::endl;
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

/***********************************************
 * @Description ghi du tu orderList vao file DonHang.txt
 ***********************************************/
void OrderList::writeFile() {
    std::ofstream writer("DonHang.txt");
    if (writer.is_open()) {
        int stt = 0;
        for (OrderModel order : _orderList) {
            ++stt;
            auto listGoods = order.getListGoods();
            double totalPrice = order.getTotalPrice();
            auto customerName = order.getCustomerName();
            auto customerAddress = order.getCustomerAddress();
            auto customerPhone = order.getCustomerPhone();
            auto orderDate = order.getOrderDate();

            writer << stt << ":"
                << customerName << ":"
                << customerAddress << ":"
                << customerPhone << ":"
                << orderDate.toString() << ":";
            for (const auto& item : listGoods) {
                writer << item.first << ":" << item.second << ":";
            }

            writer << totalPrice << "\n";
        }
        writer.close();
    }
    else {
        std::cout << "\nKhong the mo file.\n";
    }
}

/***********************************************
 * @Description hien thi tat ca don hang.
 ***********************************************/
void OrderList::displayAll() {
    i = 1;
    for (OrderModel order : _orderList) {
        goToXY(28, 3 + i);
        order.display();
        std::cout << "\n";
        i+=2;
    }
}

/**************************************************************************
 * @Description kiem tra so luong cua tung don hang co <= so hang hoa khong.
 **************************************************************************/
bool OrderList::checkGoodsNum(const std::vector<std::pair<std::string, int>>& codelist) {
    for (auto code : codelist) {
        if (code.second > _goodList.getOneGoods(code.first)) return false;
    }
    return true;
}

/**************************************************************************
 * @Description lay tung ma mat hang cua don hang sau do update so luong mat hang do
 **************************************************************************/
void OrderList::updateNumberFromCodeGoods(const std::vector<std::pair<std::string, int>> codelist) {
    for (auto code : codelist) _goodList.updateOneGoods(code.first, code.second);
}

/***********************************************
 * @Description xu ly don hang.
 ***********************************************/
void OrderList::processOrder() {
    readFile();


    if (_orderList.empty()) {
        std :: cout << std::endl;
        goToXY(28, 2);
        std::cout << "Khong co don hang nao can xu ly.\n";
        goToXY(28, 4);
        std::cout << "Nhap (ESC) de thoat.\n";
        char key = _getch();
        
        if (key == 27) {
            return;
        }
       
    }
    

    
    int code;
    while (true) {
        displayAll();
        goToXY(28, i + 3);
        std::cout << "Nhap don can xu ly: ";
        i += 3;
        std::cin >> code;
        if (code == _orderList[0].getOrderNumber()) {
            if (!checkGoodsNum(_orderList[0].getListGoods()))
            {
                goToXY(28, i + 2);
                std::cout << "Xu ly don hang that bai vi so luong hang hoa khong du.\n";
                i+=2;
            }
            else {
                updateNumberFromCodeGoods(_orderList[0].getListGoods());
                display.deleteBackGround();
                goToXY(28, 3);
                std::cout << "Xu ly thanh cong don hang! Nhan (s) de xem hang con lai, (Enter) de tiep tuc!";
                
                char key = _getch();
                goToXY(28, 3);
                std::cout << std::string(90, ' ');
                if (key == 's') {
                   
                    _goodList.showDataAsTable();
                }
                else {
                    _orderList.erase(_orderList.begin());
                    _goodList.writeToFile("HangHoa.txt");
                    writeFile();
                    continue;
                }
                std:: cout << std::endl;
                
                i += 3;
                
            }
            _orderList.erase(_orderList.begin());
            _goodList.writeToFile("HangHoa.txt");
            writeFile();
        }
        else {
            goToXY(28, i + 2);
            i += 2; 
            std::cout << "Nhap ma sai hoac khong phai la ma don hang dau tien.\n";
        }

        if (_orderList.empty()) {
            goToXY(28, i + 2);
            i += 3;
            std::cout << "Khong con don hang de xu ly.\n";
            goToXY(28, i + 2);
            i += 2;
            std::cout << "Nhap (ESC) de thoat.\n";
            char key = _getch();
            if (key == 27) {
                _goodList.writeToFile("HangHoa.txt");
                writeFile();
                break;
            }
        }
        goToXY(28, i + 2);
        i += 2;
        std::cout << "Nhap (ENTER) de tiep tuc xu ly nhap (ESC) de thoat.\n";
        char key = _getch();
        if (key == 13) {
            

            display.deleteBackGround();
            _goodList.writeToFile("HangHoa.txt");
            writeFile();
           
            continue;
        }
        else if (key == 27) {
            display.deleteBackGround();
            _goodList.writeToFile("HangHoa.txt");
            writeFile();
            break;
        }
    }

    

   
}
