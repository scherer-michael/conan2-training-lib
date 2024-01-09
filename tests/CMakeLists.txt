cmake_minimum_required(VERSION 3.15)
project(training-lib_test CXX)

find_package(spdlog REQUIRED CONFIG)
find_package(GTest REQUIRED CONFIG)

add_executable(${PROJECT_NAME}
    unit/my_lib_class_test.cpp
    "../src/my_lib_class.cpp"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        spdlog::spdlog
        GTest::gtest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
