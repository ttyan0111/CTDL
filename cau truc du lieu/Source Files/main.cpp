#include <iostream>
#include <fstream>

#include "../Header Files/models/GoodsModel.h"
#include "../Header Files/view/Display.h"
#include "../Header Files/config/UTF8.h"
#include "../Header Files\controllers/MenuMainController.h"
#include "../Header Files/config/Unordered_User.h"


int main() {
    /*setupUtf8Environment();
    MenuMainController display;
    display.start();
    return 0;*/
    // Unordered_User user;
    // DateTimeModel timeModel(12,11,2005);
    // GoodsModel goodsModel1("123","May tinh", "HCM", "Vang",
    //       123, timeModel, 12);
    //
    // user.insertFromCode("123",goodsModel1);
    // user.insertFromName("name",goodsModel1);
    // user.print();
    // char key = _getch();

    std::ifstream read("..\\Resource Files\\file txt\\users.txt");
    if (read.is_open()) {
        std::cout << "check";
    }

    std::string line;
    while (std::getline(read, line)) {
        std::cout << line << std::endl;
    }

    read.close();
}