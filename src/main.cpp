#include <iostream>

#include "models/GoodsModel.h"
#include "view/DisplayMain.h"
#include "config/UTF8.h"
#include "controllers/DisplayMainController.h"
#include "service/LoginService.h"
#include <conio.h> // Thêm thư viện này vào

int main() {
    setupUtf8Environment();
    DisplayMain displayMain;
    DisplayMainController displayMainController;
    displayMainController.setDisplayMain(displayMain);
    displayMainController.start();

    return 0;
}
