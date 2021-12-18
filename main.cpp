#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>

using namespace std;

int runTests(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Airline Database Management" << std::endl;
    return RUN_ALL_TESTS();
}



int main(){


    return 0;

}