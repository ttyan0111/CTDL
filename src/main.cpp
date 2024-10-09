#include <iostream>

#include "init/Goods.h"
#include "display/DisplayMain.h"
#include "config/UTF8.h"


int main() {
    setupUtf8Environment();
    DisplayMain menu;
    menu.displayMenu();
}