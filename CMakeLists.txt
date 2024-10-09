cmake_minimum_required(VERSION 3.29)
project(ctdlreal)

set(CMAKE_CXX_STANDARD 20)

add_executable(ctdlreal
        src/init/Goods.h
        src/init/DateTime.h
        src/display/DisplayMain.h
        src/init/Order.h
        src/config/UTF8.h
        src/main.cpp
        src/config/Font_Color.h
)
