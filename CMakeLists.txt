cmake_minimum_required(VERSION 3.7)
project(Checkers)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(Checkers ${SRC_FILES})
target_include_directories(Checkers PUBLIC ${CMAKE_CURREN_SOURCE_DIR}/include)

target_link_libraries(Checkers ${SDL2_LIBRARIES})
