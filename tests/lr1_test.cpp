#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <utility>
#include <string>

// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class LR1T : public ::testing::Test {
    protected:
        void SetUp() override {
            arr = {10, 14, 15, 20, 21, 25, 30};
        }

        void TearDown() override {
            arr.clear();
        }

        std::vector<float> arr;
        Res output;
};


std::vector<float> loadFloatsFromFile(const std::string& filepath) {
    std::ifstream input_stream(filepath);
    std::vector<float> numbers;

    for (float value; input_stream >> value;) {
        numbers.emplace_back(value);
    }

    return numbers;
}

// Пример теста 1
TEST_F(LR1T, ArraySize1025) {
// Вызываем функцию checkAndTransform с тестовыми данными
    std::vector<float> in = loadFloatsFromFile("../../cases/overflow.txt");

    Res output = checkAndTransform(in);
// Проверяем ожидаемые результаты
    EXPECT_EQ(output.errors.size(), 1);
    EXPECT_EQ(output.errors[0], "oversize");
}

// Пример теста 2
TEST_F(LR1T, ArrayEmpty) {
// Вызываем функцию checkAndTransform с тестовыми данными
    std::vector<float> in = {};
    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.errors.size(), 1);
    EXPECT_EQ(output.errors[0], "empty");
}

// Пример теста 3
TEST_F(LR1T, Overflow) {
// Вызываем функцию checkAndTransform с тестовыми данными
    std::vector<float> in = {27311111111111111111.};
    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.errors.size(), 1);
    EXPECT_EQ(output.errors[0], "overflow");
}

// Пример теста 4
TEST_F(LR1T, AloneWrong) {
    std::vector<float> in = {125.};
    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, 1);
    EXPECT_EQ(output.key_index, -1);
}

// Пример теста 5
TEST_F(LR1T, FewAndNotFirstCorrect) {
    std::vector<float> in = {125., -125., 0, 444, 21212};
    Res output = checkAndTransform(in);
// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -125);
    EXPECT_EQ(output.key_index, 1);
}

// // Пример теста 6
TEST_F(LR1T, FewAndFirstCorrect) {
    std::vector<float> in = {-125., 125., 0, 444, 21212};
    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -125);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 7
TEST_F(LR1T, FaNFC_1) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase1.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes1.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -1605973830);
    EXPECT_EQ(output.key_index, 1);
}

// Пример теста 8
TEST_F(LR1T, FaNFC_2) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase2.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes2.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -266350341);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 9
TEST_F(LR1T, FaNFC_3) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase3.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes3.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -584589412);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 10
TEST_F(LR1T, FaNFC_4) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase4.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes4.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -382953099);
    EXPECT_EQ(output.key_index, 4);
}

// Пример теста 11
TEST_F(LR1T, FaNFC_5) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase5.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes5.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -804309124);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 12
TEST_F(LR1T, FaNFC_6) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase6.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes6.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -193817790);
    EXPECT_EQ(output.key_index, 3);
}

// Пример теста 13
TEST_F(LR1T, FaNFC_7) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase7.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes7.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -178539794);
    EXPECT_EQ(output.key_index, 1);
}

// Пример теста 14
TEST_F(LR1T, FaNFC_8) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase8.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes8.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -305311751);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 15
TEST_F(LR1T, FaNFC_9) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase9.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes9.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -897141284);
    EXPECT_EQ(output.key_index, 1);
}

// Пример теста 16
TEST_F(LR1T, FaNFC_10) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase10.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes10.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -300148384);
    EXPECT_EQ(output.key_index, 3);
}

// Пример теста 17
TEST_F(LR1T, FaNFC_11) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase11.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes11.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -1028952113);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 18
TEST_F(LR1T, FaNFC_12) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase12.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes12.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -841078734);
    EXPECT_EQ(output.key_index, 1);
}

// Пример теста 19
TEST_F(LR1T, FaNFC_13) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase13.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes13.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -264523446);
    EXPECT_EQ(output.key_index, 0);
}

// Пример теста 20
TEST_F(LR1T, FaNFC_14) {
    std::vector<float> in = loadFloatsFromFile("../../cases/NormalCase14.txt");
    std::vector<float> out = loadFloatsFromFile("../../cases/NormalCaseRes14.txt");

    Res output = checkAndTransform(in);

// Проверяем ожидаемые результаты
    EXPECT_EQ(output.key, -875259555);
    EXPECT_EQ(output.key_index, 2);
}

