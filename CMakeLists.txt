cmake_minimum_required(VERSION 3.29)
project(TPSIT_ProjectWork)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_DIR src)
set(INCLUDE_DIR include)

add_library(greenhouse STATIC ${SOURCE_DIR}/greenhouse.cpp)
add_library(implant STATIC ${SOURCE_DIR}/implant.cpp)
add_library(clock STATIC ${SOURCE_DIR}/clock.cpp)
add_library(alpine STATIC ${SOURCE_DIR}/alpine.cpp)
add_library(tropical STATIC ${SOURCE_DIR}/tropical.cpp)
add_library(desertic STATIC ${SOURCE_DIR}/desertic.cpp)
add_library(mediterranean STATIC ${SOURCE_DIR}/mediterranean.cpp)
add_library(carnivorous STATIC ${SOURCE_DIR}/carnivorous.cpp)

add_executable(TPSIT_ProjectWork main.cpp)

target_link_libraries(TPSIT_ProjectWork greenhouse implant clock alpine tropical desertic mediterranean carnivorous)
