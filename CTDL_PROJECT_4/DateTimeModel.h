// DateTimeModel.h

#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <fstream>
#include "Font_Color.h"
#include <conio.h>
class DateTimeModel {
private:
    int day = 1, month = 1, year = 1900; // Giá trị mặc định
    std::string date = "";

    // Kiểm tra tính hợp lệ của ngày
    static bool isValidDate(int day, int month, int year);

public:
    // Constructor
    DateTimeModel();
    DateTimeModel(int day, int month, int year);

    [[nodiscard]] int getDay() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    void display() const;

    bool checkDateFormat(const std::string date);

    friend std::istream& operator>>(std::istream& is, DateTimeModel& dt);
    friend std::ostream& operator<<(std::ostream& os, const DateTimeModel& dt);

    std::string toString();
    void saveToFile(std::ofstream& outfile);
    void setToCurrentDate();
};

#endif // DATETIME_H
