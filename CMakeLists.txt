cmake_minimum_required(VERSION 3.0)
set(PROJECT "Stash")
project(${PROJECT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

set(HEADERS ${INCLUDE_DIR}/stash.hpp)
set(SOURCES ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/stash.cpp)

add_executable(${PROJECT} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT} PRIVATE ${INCLUDE_DIR})