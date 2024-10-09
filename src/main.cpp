#include <iostream>

#include "models/Goods.h"
#include "view/DisplayMain.h"
#include "config/UTF8.h"


int main() {
    setupUtf8Environment();
    DisplayMain menu;
    menu.displayMenu();
}