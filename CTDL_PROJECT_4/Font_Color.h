#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <windows.h>
#include <cwchar>
// Hàm thay đổi màu sắc văn bản và nền
void setColor(int textColor, int backgroundColor);
// Hàm căn giữa văn bản
void centerText(const std::string& text);
void goToXY(int x, int y);

#endif // COLOR_H
