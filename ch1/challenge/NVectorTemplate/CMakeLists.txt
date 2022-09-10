cmake_minimum_required(VERSION 3.5)

project(NVectorTemplate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NVectorTemplate main.cpp)

install(TARGETS NVectorTemplate
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
