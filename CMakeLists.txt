cmake_minimum_required(VERSION 3.15)
project(training-lib CXX)

find_package(spdlog REQUIRED)

add_library(${PROJECT_NAME}
    src/my_lib_class.h
    src/my_lib_class.cpp
    src/trainingLib.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
        FILES
            "include/trainingLib/trainingLib.h"
)

# target_include_directories(${PROJECT_NAME}
#     PUBLIC
#         "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
#         "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
# )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        spdlog::spdlog
)

enable_testing()
add_subdirectory(tests)

install(
    TARGETS ${PROJECT_NAME}
    FILE_SET HEADERS
)
