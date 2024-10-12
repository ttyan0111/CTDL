#include <iostream>

#include "models/GoodsModel.h"
#include "view/Display.h"
#include "config/UTF8.h"
#include "controllers/DisplayMainController.h"
#include "service/LoginService.h"
#include <conio.h> // Thêm thư viện này vào

int main() {
    setupUtf8Environment();
    DisplayMainController display;
    display.start();

    return 0;
}
