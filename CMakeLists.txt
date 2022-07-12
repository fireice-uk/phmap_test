cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(phmap_test)

add_executable(phmap_test main.cpp)

install(TARGETS phmap_test RUNTIME DESTINATION bin)
