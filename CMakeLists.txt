cmake_minimum_required(VERSION 2.8.10)
project(get_space_info)

include (FindPkgConfig)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

message(CMAKE_GENERATOR: ${CMAKE_GENERATOR})

message("Compiler version: " ${CMAKE_CXX_COMPILER_ID} "-" ${CMAKE_CXX_COMPILER_VERSION})
message("CMAKE_BUILD_TYPE:" ${CMAKE_BUILD_TYPE})

if((CMAKE_MAJOR_VERSION LESS 3) OR ((CMAKE_MAJOR_VERSION LESS 4) AND (CMAKE_MINOR_VERSION LESS 3))) # less or equal than cmake 3.2
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") AND (NOT ("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "3.9")))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-expansion-to-defined")
endif()

find_package(Boost 1.54.0 REQUIRED COMPONENTS system filesystem)

include_directories(${SRC_DIR})
include_directories(${Boost_INCLUDE_DIRS})

# ApiGui, ApiIw, ApiOptima are not together since together they eat to MUCH memory

set (SOURCE_FILES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_options(${PROJECT_NAME} PRIVATE -fexceptions)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
