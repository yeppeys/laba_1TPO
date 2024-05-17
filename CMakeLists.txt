cmake_minimum_required(VERSION 3.10)
project(lr1_project)

set(CMAKE_CXX_STANDARD 17)

# Добавляем все исходные файлы для библиотеки
add_library(lr1_library src/lr1.cpp)

# Тесты
add_executable(runTests tests/lr1_test.cpp)

# Указываем директории для заголовочных файлов
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/json/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include)

# Добавляем Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(runTests lr1_library ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

add_test(NAME runTests COMMAND runTests)
