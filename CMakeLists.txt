cmake_minimum_required(VERSION 3.20)
project(stopwatch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src/")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main "${SRC_DIR}/main.cpp")
target_link_libraries(main ${CURSES_LIBRARIES})
