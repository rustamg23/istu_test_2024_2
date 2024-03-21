#include <gtest/gtest.h>
#include "functions.h"


class CheckAndTransformTest : public ::testing::Test {
protected:
    vector<float> arr;

    void SetUp() override {
        // Инициализация, общая для всех тестов, может быть выполнена здесь
    }

    void TearDown() override {
        // Код очистки, если необходим
        arr.clear();
    }
};

TEST_F(CheckAndTransformTest, TransformOccurs) {
    arr = {-99.034, 222222222222222222222222222222.2, 11.24140, 0.0214, -1.021424, 0.1245, 1.0};
    EXPECT_TRUE(checkAndTransform(arr));
}

TEST_F(CheckAndTransformTest, Original) {
    arr = {10.1221, -14.14243, 15.11111, -20.543312, 21.64345, -25.75453, 30.46764};
    EXPECT_TRUE(checkAndTransform(arr));
}

TEST_F(CheckAndTransformTest, NoTransformNeeded) {
    arr = {4.4220, 1.1245, 2.2121, 3.02211, 4.0424, 5.04241, 6.242420};
    EXPECT_FALSE(checkAndTransform(arr));
}

TEST_F(CheckAndTransformTest, EdgeCases) {
    arr = {}; // Пустой массив
    EXPECT_FALSE(checkAndTransform(arr));
}

TEST_F(CheckAndTransformTest, Ones) {
    arr = {-15.0, -6.0, 22.0, 33.0, 11.1111111}; // Пустой массив
    EXPECT_TRUE(checkAndTransform(arr));
}
