#include "MenuManagerController.h"

MenuManagerController::MenuManagerController() : isLocked(false), remainingTime(0) {
}

// Bắt đầu quản lý
void MenuManagerController::start() {
    if (isLogin) {
        while (true) {
            display.displayManager();
            if (handleSelection()) {
                break;
            }
        }
    }
    else if (isCurrentlyLocked()) {
    }
    else if (login()) {
        while (true) {
            display.displayManager();
            if (handleSelection()) {
                break;
            }
        }
    }
    else {
        goToXY(28, 24);
        std::cout << "Dang nhap that bai!. Nhan phim ESC de quay lai menu chinh...\n";
        while (true) {
            char key = _getch(); // Chờ nhấn phím bất kỳ để quay lại menu chính
            if (key == 27) {
                break;
            }
        }
    }
}

// Xử lý lựa chọn sau khi đăng nhập thành công
bool MenuManagerController::handleSelection() {
    OrderList orderList;
    int selection = display.getSelectedManage();
    switch (selection) {
    case 1:
        orderList.processOrder();
        break;
    case 2:
        managerGoods.start();
        return false;
    case 3:
        return true;
    default:
        return false;
    }
}

// Hàm chạy ngầm để đếm thời gian khóa
void MenuManagerController::lockCountdown(int seconds) {
    isLocked = true;
    remainingTime = seconds;

    // Chạy luồng riêng để đếm ngược
    std::thread([this]() {
        while (remainingTime > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            remainingTime--;
        }
        isLocked = false; // Mở khóa sau khi hết thời gian
        }).detach(); // Detach để luồng chạy ngầm
}

bool MenuManagerController::isCurrentlyLocked() {
    if (isLocked) {
        char key;
        key = 1;

        // Lưu vị trí của dòng hiển thị
        COORD cursorPos;
        cursorPos.Y = 0; // Vị trí Y của dòng hiển thị
        cursorPos.X = 0; // Vị trí X bắt đầu
        display.deleteBackGround();
        while (key != 27) {
            // Di chuyển con trỏ về vị trí mong muốn
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
            goToXY(28, 3);
            // In lại dòng thông báo
            setColor(12, 0);
            std::cout << "Chuc nang dang bi khoa! Con " << remainingTime << " giay... ";
            // Dấu cách để xóa thông tin cũ
            goToXY(28, 5);
            std::cout << "(Nhan ESC de thoat)";
            std::cout << "\r"; // Di chuyển con trỏ về đầu dòng
            setColor(7, 0);
            // Kiểm tra phím nhấn
            if (_kbhit()) {
                key = _getch();
                if (key == 27) {
                    // ESC key
                    return true; // Thoát khỏi khóa
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Tạm dừng để giảm tần suất cập nhật
        }
    }
    return false;
}

// Hàm xử lý đăng nhập
bool MenuManagerController::login() {
    const int MAX_ATTEMPTS = 3;
    int attemptsLeft = MAX_ATTEMPTS;

    while (attemptsLeft > 0) {
        if (checkLogin()) {
            std::cout << "Dang nhap thanh cong!\n";
            isLogin = true;
            return true;
        }
        else {
            attemptsLeft--;
            goToXY(28, 22);
            setColor(12, 0); 
            std::cout << "Sai thong tin dang nhap! Con "
                << attemptsLeft << " lan thu.\n";

            if (attemptsLeft == 0) {
                lockCountdown(15); // Khóa 5 phút (300 giây)
                return false;
            }
            setColor(7, 0);
        }
        goToXY(28, 24);
        std::cout << "Tiep tuc (Enter) hoac Thoat (ESC): ";
        // Chờ người dùng nhấn Enter hoặc ESC
        while (true) {
            char key = _getch();
            if (key == 27) {
                // ESC
                return false;
            }
            else if (key == 13) {
                // Enter
                break;
            }
        }
    }
    return false;
}

// Kiểm tra thông tin đăng nhập
bool MenuManagerController::checkLogin() {
    std::string username, password;
    Display::hienThiGiaoDienChinh();
    
    hienThiDangNhap();
    
    
    goToXY(28, 16);
    std::cout << "NHAP TEN DANG NHAP:";
    if (std::cin.peek() == '\n') {
        std::cin.ignore(); // Loại bỏ ký tự '\n' nếu có
    }
    

    std::getline(std::cin, username);
    goToXY(28, 18);
    std::cout << "NHAP MAT KHAU: ";
    char ch;
    while ((ch = _getch()) != 13) { // 13 là mã ASCII của phím Enter
        if (ch == 8) { // 8 là mã ASCII của phím Backspace
            if (!password.empty()) {
                std::cout << "\b \b"; // Xóa ký tự cuối cùng của dấu *
                password.pop_back();
            }
        }
        else {
            password += ch;
            std::cout << '*'; // Hiển thị dấu *
        }
    }
    return loginService.authenticate(username, password);
}
void MenuManagerController::hienThiDangNhap() {
    std::string line;
    int i = 1;
    std::ifstream file("../dangNhap.txt");
    setColor(0, 0);
    while (getline(file, line)) { // Đọc từng dòng từ file
        goToXY(26, 0 + i + 1);
        for (char c : line) {
            if (c == '*'  || c == '.' || c==',') {
                setColor(11, 11);
            }
            else {
                setColor(0, 0);
            }
            std::cout << c;
        }
        std::cout << std::endl;
        i++;
    }
    setColor(7, 0); // Đặt lại màu mặc định khi kết thúc
    file.close();
}

