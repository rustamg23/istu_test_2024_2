cmake_minimum_required(VERSION 3.28.3)
project(YourProjectName)

# Устанавливаем C++ стандарт
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем исполняемый файл проекта
# Указываем CMake включить и main.cpp и functions.cpp в сборку исполняемого файла
add_executable(YourProject ./bin/main.cpp ./src/functions.cpp)

# Включаем тестирование
enable_testing()

# Находим пакет GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавляем директорию с заголовочными файлами, чтобы и main.cpp, и тесты могли их использовать
include_directories(./include)

# Добавляем исполняемый файл для тестов
# Указываем CMake включить и тесты, и functions.cpp в сборку исполняемого файла тестов
add_executable(main_test ./test/main_test.cpp ./src/functions.cpp)
target_link_libraries(main_test GTest::gtest_main pthread)

# Добавляем тесты
add_test(NAME main_test COMMAND main_test)

target_include_directories(main_test PUBLIC ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(main_test)