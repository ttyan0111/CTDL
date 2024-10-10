cmake_minimum_required(VERSION 3.29)
project(ctdlreal)

set(CMAKE_CXX_STANDARD 20)

add_executable(ctdlreal
        src/models/GoodsModel.h
        src/models/DateTimeModel.h
        src/view/DisplayMain.h
        src/models/OrderModel.h
        src/config/UTF8.h
        src/main.cpp
        src/config/Font_Color.h
        src/controllers/FindInforGoods.h
        src/controllers/DisplayInforGoods.h
        src/controllers/OrderGoods.h
        src/controllers/Manage.h
        src/models/AccountModel.h
        src/controllers/DisplayMainController.h
)
