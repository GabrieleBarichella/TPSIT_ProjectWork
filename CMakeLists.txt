cmake_minimum_required(VERSION 3.29)
project(TPSIT_ProjectWork)

set(CMAKE_CXX_STANDARD 20)

add_executable(TPSIT_ProjectWork main.cpp
        include/greenhouse.h
        src/greenhouse.cpp
        include/clock.h
        src/clock.cpp
        include/implant.h
        src/implant.cpp
        include/tropical.h
        include/desertic.h
        include/alpine.h
        include/carnivorous.h
        include/mediterranean.h
        src/alpine.cpp
        src/carnivorous.cpp
        src/desertic.cpp
        src/mediterranean.cpp
        src/tropical.cpp
        include/inputSystem.h
        src/inputSystem.cpp)
