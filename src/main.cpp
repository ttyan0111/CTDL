#include <iostream>

#include "models/GoodsModel.h"
#include "view/DisplayMain.h"
#include "config/UTF8.h"
#include "controllers/DisplayMainController.h"


int main() {
    setupUtf8Environment();
    DisplayMainController controller;
    controller.start();
}
