cmake_minimum_required(VERSION 3.20)
project(stopwatch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src/")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB_RECURSE STOPWATCH_SRC "${SRC_DIR}/*.cpp")

add_executable(stopwatch "${SRC_DIR}/main.cpp"
                    ${STOPWATCH_SRC})
target_link_libraries(stopwatch ${CURSES_LIBRARIES})

install(TARGETS stopwatch DESTINATION "~/.local/bin/")
