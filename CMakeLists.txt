cmake_minimum_required(VERSION 3.20)
project(AirlineDatabaseManagement)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(AirlineDatabaseManagement main.cpp Tests/tests.cpp Tests/Aviao.h Tests/Aviao.cpp Tests/Voo.h Tests/Voo.cpp
        Tests/Servico.h Tests/Servico.cpp Tests/Passageiro.h Tests/Passageiro.cpp Tests/Bilhete.h Tests/Bilhete.cpp)

target_link_libraries(AirlineDatabaseManagement gtest gtest_main)