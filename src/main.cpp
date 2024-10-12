#include <iostream>

#include "models/GoodsModel.h"
#include "view/Display.h"
#include "config/UTF8.h"
#include "controllers/DisplayMainController.h"
#include "service/LoginService.h"
#include <conio.h> // Thêm thư viện này vào

#include "config/Unordered_User.h"

int main() {
    // setupUtf8Environment();
    // DisplayMainController display;
    // display.start();
    // return 0;
    Unordered_User user;
    DateTimeModel timeModel(12,11,2005);
    GoodsModel goodsModel1("123","May tinh", "HCM", "Vang",
          123, timeModel, 12);

    user.insertFromCode("123",goodsModel1);
    user.insertFromName("name",goodsModel1);
    user.print();
    char key = _getch();

}
