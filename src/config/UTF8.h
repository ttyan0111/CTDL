#ifndef UTF8SETUP_H
#define UTF8SETUP_H

#ifdef _WIN32
#include <windows.h>  // Chỉ cần cho Windows
#endif
#include <locale>      // Sử dụng cho Linux/macOS
void setupUtf8Environment() {
#ifdef _WIN32
    // Cấu hình cho Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#else
    // Cấu hình cho Linux/macOS
    setlocale(LC_ALL, "");
#endif
}

#endif // UTF8SETUP_H