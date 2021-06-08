cmake_minimum_required(VERSION 3.10)
project(tps)

set(HEADERS
        pwm.hpp)

set(SOURCES
        pwm.cpp
        main.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
