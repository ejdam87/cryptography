cmake_minimum_required(VERSION 3.21)
project(cyphers C)

set(CMAKE_C_STANDARD 11)

add_executable( cyphers pow.c pow.h congruence.c congruence.h )
