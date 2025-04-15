cmake_minimum_required(VERSION 3.10)
project(CalcolatriceTest C)

set(CMAKE_C_STANDARD 99)

# Aggiunge i file sorgente
add_library(calcolatrice calcolatrice.c)

# Abilita i test
enable_testing()

# Trova GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Aggiunge il test
add_executable(test_calcolatrice main_test.cpp)
target_link_libraries(test_calcolatrice calcolatrice ${GTEST_LIBRARIES} pthread)

# Aggiunge il test a CTest
add_test(NAME CalcolatriceTest COMMAND test_calcolatrice)
