cmake_minimum_required(VERSION 3.13)
project(mysteryWord)

set(CMAKE_CXX_STANDARD 14)

add_executable(mysteryWord main.cpp)
file(REMOVE mysteryWord)
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/mysteryWord
        DESTINATION ../)