cmake_minimum_required(VERSION 2.6)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(switch)

add_executable(switchTest switchTest.cpp )
TARGET_LINK_LIBRARIES(switchTest)

enable_testing()

ADD_DEFINITIONS("-std=c++0x") 

macro(add_test_diff name file command)
  add_test(${name} python cmdiff.py ${file} ${command})
endmacro(add_test_diff)

add_test(help bin/switchTest)
