#include "gtest/gtest.h"
#include "gmock/gmock.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Airline Database Management" << std::endl;
    return RUN_ALL_TESTS();
}
