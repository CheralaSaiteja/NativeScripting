cmake_minimum_required(VERSION 3.8)
project(NativeScripting VERSION 0.1)

option(BUILD_TESTS "Enable to build tests" ON)
file(GLOB SRC src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include/)
set_target_properties(NativeScripting PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
if(BUILD_TESTS)
    add_library(testLib SHARED tests/testlib.cpp)
    add_executable(testExec tests/main.cpp)

    target_link_libraries(testExec NativeScripting)
    target_include_directories(testExec PUBLIC include/)
endif(BUILD_TESTS)
