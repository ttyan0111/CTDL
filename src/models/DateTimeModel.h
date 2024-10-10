//
// Created by giang on 10/8/24.
//

#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <stdexcept> // Thêm thư viện để sử dụng std::invalid_argument

class DateTimeModel {
private:
    int day = 1, month = 1, year = 1900; // Giá trị mặc định

    // Kiểm tra tính hợp lệ của ngày
    bool isValidDate(int day, int month, int year) {
        if (year < 1 || month < 1 || month > 12 || day < 1) {
            return false; // Ngày, tháng, năm không hợp lệ
        }
        // Kiểm tra số ngày trong tháng
        if (month == 2) {
            // Kiểm tra năm nhuận
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            return (day <= (isLeapYear ? 29 : 28));
        }
        // Kiểm tra số ngày tối đa trong các tháng khác
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return (day <= 30);
        }
        return (day <= 31); // Ngày hợp lệ cho các tháng khác
    }

public:
    // Constructor
    DateTimeModel() = default;

    DateTimeModel(int day, int month, int year) {
        if (!isValidDate(day, month, year)) {
            throw std::invalid_argument("Invalid date provided.");
        }
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    [[nodiscard]] int getDay() const { return this->day; }
    [[nodiscard]] int getMonth() const { return this->month; }
    [[nodiscard]] int getYear() const { return this->year; }

    void setDay(int day) {
        if (isValidDate(day, month, year)) {
            this->day = day;
        } else {
            throw std::invalid_argument("Invalid day for the current month/year.");
        }
    }

    void setMonth(int month) {
        if (isValidDate(day, month, year)) {
            this->month = month;
        } else {
            throw std::invalid_argument("Invalid month.");
        }
    }

    void setYear(int year) {
        if (year > 0) { // Có thể cho phép năm âm để xử lý dễ dàng hơn
            this->year = year;
        }
        else {
            throw std::invalid_argument("Invalid Year.");
        }
    }



    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

#endif // DATETIME_H