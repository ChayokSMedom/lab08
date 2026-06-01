cmake_minimum_required(VERSION 3.10)
project(lab05 VERSION 1.0 LANGUAGES CXX)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

# Создаём интерфейсную библиотеку для header-only
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} gtest_main)
  target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  add_test(NAME check COMMAND check)
endif()

include(CPackConfig.cmake)
