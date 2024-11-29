// DateTimeModel.cpp

#include "DateTimeModel.h"

// Hàm kiểm tra tính hợp lệ của ngày
bool DateTimeModel::isValidDate(int day, int month, int year) {
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

// Constructor mặc định
DateTimeModel::DateTimeModel() = default;

// Constructor với ngày, tháng, năm
DateTimeModel::DateTimeModel(int day, int month, int year) {
    if (!isValidDate(day, month, year)) {
        throw std::invalid_argument("Invalid date provided.");
    }
    setDay(day);
    setMonth(month);
    setYear(year);
}

int DateTimeModel::getDay() const { return this->day; }
int DateTimeModel::getMonth() const { return this->month; }
int DateTimeModel::getYear() const { return this->year; }

void DateTimeModel::setDay(int day) {
    if (isValidDate(day, month, year)) {
        this->day = day;
    }
    else {
        throw std::invalid_argument("Invalid day for the current month/year.");
    }
}

void DateTimeModel::setMonth(int month) {
    if (isValidDate(day, month, year)) {
        this->month = month;
    }
    else {
        throw std::invalid_argument("Invalid month.");
    }
}

void DateTimeModel::setYear(int year) {
    if (year > 0) { // Có thể cho phép năm âm để xử lý dễ dàng hơn
        this->year = year;
    }
    else {
        throw std::invalid_argument("Invalid Year.");
    }
}

void DateTimeModel::display() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}

bool DateTimeModel::checkDateFormat(const std::string date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') {
        std::cerr << "Da xay ra loi: Dinh dang khong dung. Vui long nhap theo đinh dang dd/MM/yyyy." << std::endl;
        return false;
    }

    std::stringstream ss(date);
    std::string token;
    int d, m, y;

    std::getline(ss, token, '/');
    try {
        d = std::stoi(token);
    }
    catch (const std::invalid_argument&) {
        std::cerr << "Da xay ra loi: Dinh dang khong dung." << std::endl;
        return false;
    }

    std::getline(ss, token, '/');
    try {
        m = std::stoi(token);
    }
    catch (const std::invalid_argument&) {
        std::cerr << "Da xay ra loi: Dinh dang khong dung" << std::endl;
        return false;
    }

    std::getline(ss, token);
    try {
        y = std::stoi(token);
    }
    catch (const std::invalid_argument&) {
        std::cerr << "Da xay ra loi: Dinh dang khong dung" << std::endl;
        return false;
    }

    if (!isValidDate(d, m, y)) {
        std::cerr << "Da xay ra loi: Ngay khong hop le" << std::endl;
        return false;
    }

    setDay(d);
    setMonth(m);
    setYear(y);

    return true;
}

std::istream& operator>>(std::istream& is, DateTimeModel& dt) {
    while (true) {
        std::cout << "Ngay nhap(dd/MM/yyyy): ";
        is >> dt.date;
        if (dt.checkDateFormat(dt.date)) {
            return is;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const DateTimeModel& dt) {
    std::string data = std::to_string(dt.day) + "/" + std::to_string(dt.month) + "/" + std::to_string(dt.year);
    os << data;
    return os;
}

std::string DateTimeModel::toString() {
    return std::to_string(getDay()) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

void DateTimeModel::saveToFile(std::ofstream& outfile) {
    outfile << toString() << "\n";
}

void DateTimeModel::setToCurrentDate() {
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);  // Sử dụng localtime_s thay vì localtime

    year = now.tm_year + 1900;
    month = now.tm_mon + 1;
    day = now.tm_mday;
}
