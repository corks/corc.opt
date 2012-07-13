cmake_minimum_required(VERSION 2.8.7)
project(corc.opt C)

set(CMAKE_BUILD_TYPE Debug)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CC_FLAGS_DEBUG
        "-ansi -g -pedantic -pg -Wall -Werror -Wextra")

    set(CMAKE_CC_FLAGS_RELEASE "-ansi -O2")
endif (CMAKE_COMPILER_IS_GNUCC)

add_subdirectory(src)
