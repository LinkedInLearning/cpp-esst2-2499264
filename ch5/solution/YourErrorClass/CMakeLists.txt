cmake_minimum_required(VERSION 3.5)

project(YourErrorClass LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(YourErrorClass main.cpp)

install(TARGETS YourErrorClass
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
