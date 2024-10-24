//
// Created by giang on 10/8/24.
// 

#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <stdexcept> // Thêm thư viện để sử dụng std::invalid_argument
#include <sstream>   // Thư viện để sử dụng std::stringstream
#include <string>

class DateTimeModel {
private:
    int day = 1, month = 1, year = 1900; // Giá trị mặc định
    std::string date = "";

    // Kiểm tra tính hợp lệ của ngày
    static bool isValidDate(int day, int month, int year) {
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
        }
        else {
            throw std::invalid_argument("Invalid day for the current month/year.");
        }
    }

    void setMonth(int month) {
        if (isValidDate(day, month, year)) {
            this->month = month;
        }
        else {
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

    bool checkDateFormat(const std::string date) {
        // Kiểm tra định dạng ngày: phải có 2 ký tự số, 1 ký tự '/', 2 ký tự số, 1 ký tự '/', 4 ký tự số
        if (date.length() != 10 || date[2] != '/' || date[5] != '/') {
            std::cerr << "Đã xảy ra lỗi: Định dạng không đúng. Vui lòng nhập theo định dạng dd/MM/yyyy." << std::endl;
            return false;
        }

        // Tách ngày, tháng, năm
        std::stringstream ss(date);
        std::string token;
        int d, m, y;

        std::getline(ss, token, '/'); // Ngày
        try {
            d = std::stoi(token);
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Đã xảy ra lỗi: Định dạng không đúng." << std::endl;
            return false; // Trả về false nếu có lỗi khi chuyển đổi
        }

        std::getline(ss, token, '/'); // Tháng
        try {
            m = std::stoi(token);
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Đã xảy ra lỗi: Định dạng không đúng." << std::endl;
            return false; // Trả về false nếu có lỗi khi chuyển đổi
        }

        std::getline(ss, token); // Năm
        try {
            y = std::stoi(token);
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Đã xảy ra lỗi: Định dạng không đúng." << std::endl;
            return false; // Trả về false nếu có lỗi khi chuyển đổi
        }

        // Kiểm tra tính hợp lệ của ngày
        if (!isValidDate(d, m, y)) {
            std::cerr << "Đã xảy ra lỗi: Ngày không hợp lệ." << std::endl;
            return false; // Trả về false nếu ngày không hợp lệ
        }

        // Nếu ngày, tháng, năm hợp lệ, thiết lập giá trị
        setDay(d);
        setMonth(m);
        setYear(y);
        return true; // Trả về true nếu định dạng và giá trị hợp lệ
    }

    friend std::istream& operator>>(std::istream& is, DateTimeModel& dt) {
        while (true) {
            std::cout << "Ngày nhập(dd/MM/yyyy): ";
            is >> dt.date;
            if (dt.checkDateFormat(dt.date)) {
                return is;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const DateTimeModel& dt) {
        std::string date = std::to_string(dt.day) + "/" + std::to_string(dt.month) + "/" + std::to_string(dt.year);
        os << date;
        return os;
    }
};

#endif // DATETIME_H
