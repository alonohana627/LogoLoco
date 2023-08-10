cmake_minimum_required(VERSION 3.26)
project(LogoLoco)
set(CMAKE_CXX_STANDARD 23)

include_directories(include lib)

add_executable(Main lib/main.cpp)
#target_(LogoLoco lib/main.cpp)

find_package(GTest CONFIG REQUIRED)
enable_testing()
