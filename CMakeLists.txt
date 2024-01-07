cmake_minimum_required(VERSION 3.14)

project("Haven Launcher"
    VERSION 0.1.0
    DESCRIPTION "a game launcher written specifically for lower elements games"
    LANGUAGES CXX
    )

# Global project options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

add_executable(haven src/main.cpp)
install(TARGETS haven DESTINATION bin)
