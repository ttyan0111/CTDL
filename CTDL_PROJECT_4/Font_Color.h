#ifndef COLOR_H
#define COLOR_H

#include <string>

// Hàm thay đổi màu sắc văn bản và nền
void setColor(int textColor, int backgroundColor);

// Hàm thay đổi kích thước font chữ
void setFontSize(int fontSize);

// Hàm căn giữa văn bản
void centerText(const std::string& text);

#endif // COLOR_H
