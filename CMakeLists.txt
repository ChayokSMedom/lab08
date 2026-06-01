cmake_minimum_required(VERSION 3.10)
project(lab05 VERSION 1.0 LANGUAGES CXX)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

# Создаём интерфейсную библиотеку для header-only
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Print library
add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(print ${PROJECT_NAME})

if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    
    add_executable(check ${CMAKE_CURRENT_SOURCE_DIR}/tests/check.cpp)
    target_link_libraries(check print GTest::gtest_main)
    target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    add_test(NAME check COMMAND check)
endif()

if(BUILD_EXAMPLES)
    add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
    target_link_libraries(example print)
    target_include_directories(example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    install(TARGETS example RUNTIME DESTINATION bin)
endif()

# Demo application
add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)
target_link_libraries(demo print)
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(TARGETS demo RUNTIME DESTINATION bin)

# Install targets
install(TARGETS print ARCHIVE DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
