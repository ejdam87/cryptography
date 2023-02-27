cmake_minimum_required(VERSION 3.16)
project(symetric C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(symetric
        ceasar.c
        ceasar.h
        alphabet.h)
