#include<iostream>
#include "MenuMainController.h"
#include <fstream>
#include <string>
#include "Font_Color.h"
#include "MenuManagerGoodsController.h"
using namespace std;

int main() {

    //std::string line;
    //std::ifstream file("../giaodien.txt");
    //while (getline(file, line)) { // Đọc từng dòng từ file
    //    for (char c : line) { // Duyệt từng ký tự
    //        if (c == '&' || c == '@' || c == '%' || c == '#' || c == '*' || c == '?' || c == '/' ) {
    //            setColor(10, 10); // Màu xám (Text: xám, Nền: đen)
    //            std::cout << c;
    //        }
    //        else {
    //            setColor(7, 0); // Mặc định (Text: trắng, Nền: đen)
    //            std::cout << c;
    //        }
    //    }
    //    std::cout << std::endl; // Xuống dòng
    //}
    //setColor(7, 0); // Đặt lại màu mặc định khi kết thúc
    
   


    

    MenuMainController display;
    display.start();
   /* MenuManagerGoodsController x;
    x.start();*/
    

    
}
