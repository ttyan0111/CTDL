#include <iostream>

#include "init/Goods.h"
#include "display/DisplayMain.h"
#include "init/UTF8.h"


int main() {
    setupUtf8Environment();
    DisplayMain menu;
    menu.displayMenu();
}