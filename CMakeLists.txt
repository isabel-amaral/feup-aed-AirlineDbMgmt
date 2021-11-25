cmake_minimum_required(VERSION 3.20)
project(AirlineDatabaseManagement)

set(CMAKE_CXX_STANDARD 14)

add_executable(AirlineDatabaseManagement main.cpp Tests/Aviao.h Tests/Aviao.cpp Tests/Voo.h Tests/Voo.cpp)
