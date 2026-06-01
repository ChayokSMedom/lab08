#include "print.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(PrintTest, BasicPrint) {
    std::stringstream ss;
    print("Hello, World!", ss);
    EXPECT_EQ(ss.str(), "Hello, World!");
}

TEST(PrintTest, EmptyString) {
    std::stringstream ss;
    print("", ss);
    EXPECT_EQ(ss.str(), "");
}

TEST(PrintTest, MultiplePrints) {
    std::stringstream ss;
    print("Hello", ss);
    print(" ", ss);
    print("World!", ss);
    EXPECT_EQ(ss.str(), "Hello World!");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
