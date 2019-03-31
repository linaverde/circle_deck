cmake_minimum_required(VERSION 3.12)
project(circle_deck)

set(CMAKE_CXX_STANDARD 14)

add_executable(circle_deck main.cpp deck_lib.cpp deck_lib.h)

add_executable(test test-main.cpp tests.cpp deck_lib.cpp deck_lib.h)