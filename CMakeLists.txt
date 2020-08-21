cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(PROJECT "Stash_ex")
set(LIBRARY "Stash")
project(${PROJECT} LANGUAGES CXX)

option(USE_LIBRARY "Compile sources into a library" OFF)
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

include(CMakeDependentOption)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
  "USE_LIBRARY" ON
  )

cmake_dependent_option(
  MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
  "USE_LIBRARY" ON
  )

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

list(APPEND _sources ${INCLUDE_DIR}/stash.hpp ${SOURCE_DIR}/stash.cpp)

if(USE_LIBRARY)
  message(STATUS "Compile sources into a STATIC library? ${MAKE_STATIC_LIBRARY}")
  message(STATUS "Compile sources into a SHARED library? ${MAKE_SHARED_LIBRARY}")

  if(MAKE_SHARED_LIBRARY)
    add_library(${LIBRARY} SHARED ${_sources})
    target_include_directories(${LIBRARY} PRIVATE ${INCLUDE_DIR})

    add_executable(${PROJECT} ${SOURCE_DIR}/main.cpp)
    target_include_directories(${PROJECT} PRIVATE ${INCLUDE_DIR})
    target_link_libraries(${PROJECT} ${LIBRARY})
  endif()

  if(MAKE_STATIC_LIBRARY)
  add_library(${LIBRARY} STATIC ${_sources})
  target_include_directories(${LIBRARY} PRIVATE ${INCLUDE_DIR})

  add_executable(${PROJECT} ${SOURCE_DIR}/main.cpp)
  target_include_directories(${PROJECT} PRIVATE ${INCLUDE_DIR})
  target_link_libraries(${PROJECT} ${LIBRARY})
  endif()
else()
  add_executable(${PROJECT} ${SOURCE_DIR}/main.cpp ${_sources})
  target_include_directories(${PROJECT} PRIVATE ${INCLUDE_DIR})
endif()
