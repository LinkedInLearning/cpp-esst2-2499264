cmake_minimum_required(VERSION 3.5)

project(groupingWords LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(groupingWords main.cpp)

install(TARGETS groupingWords
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
