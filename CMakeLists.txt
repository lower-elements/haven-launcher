cmake_minimum_required(VERSION 3.24)

project("Haven Launcher"
    VERSION 0.1.0
    DESCRIPTION "a game launcher written specifically for lower elements games"
    LANGUAGES CXX
    )
# Global project options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (WIN32)
set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()

# Dependencies
find_package(wxWidgets COMPONENTS core base)
if (NOT wxWidgets_FOUND)
include(FetchContent)

message(STATUS "Building wxWidgets from source instead")
set(wxWidgets_USE_STATIC 1)
    set(wxBUILD_SHARED OFF CACHE BOOL "Build wx libraries as shared libs")
    set(wxBUILD_PRECOMP ON CACHE BOOL "Use precompiled headers")
    #set(wxBUILD_MONOLITHIC OFF CACHE BOOL "Build a single library")
    FetchContent_Declare(
        wxWidgets 
        URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.zip
        URL_HASH MD5=49519875d88babf4ad5ab91243026265
  TLS_VERIFY true
  DOWNLOAD_EXTRACT_TIMESTAMP true
    )
    
    FetchContent_MakeAvailable(wxWidgets)
endif()
    include(${wxWidgets_USE_FILE})

    set(SOURCE_FILES src/app.cpp src/main_frame.cpp src/preferences.cpp)

    add_executable(haven WIN32 ${SOURCE_FILES} src/haven.rc)

    target_include_directories(haven PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    if(wxWidgets_FOUND)
    target_compile_definitions(haven PRIVATE ${wxWidgets_DEFINITIONS})
    target_include_directories(haven PRIVATE ${wxWidgets_INCLUDE_DIRS})
    target_link_directories(haven PRIVATE ${wxWidgets_LIBRARY_DIRS})
    target_link_libraries(haven ${wxWidgets_LIBRARIES})
else()
    target_link_libraries(haven PRIVATE wx::base wx::core)
    endif()

# Warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(haven PRIVATE -Wall -Wextra -pedantic)
elseif(MSVC)
    target_compile_options(haven PRIVATE /W4)
endif()

install(TARGETS haven DESTINATION bin)
