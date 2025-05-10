cmake_minimum_required(VERSION 3.29)
project(TPSIT_ProjectWork)

set(CMAKE_CXX_STANDARD 20)

add_executable(TPSIT_ProjectWork main.cpp
        include/greenhouse.h
        src/greenhouse.cpp
        include/clock.h
        src/clock.cpp
        include/implant.h
        src/implant.cpp)
