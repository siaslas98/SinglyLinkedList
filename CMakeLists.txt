cmake_minimum_required(VERSION 3.27)
project(SinglyLinkedList)

set(CMAKE_CXX_STANDARD 14)

# Add the main executable
add_executable(SinglyLinkedList main.cpp)

# Enable testing
enable_testing()

# Add GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(runTests tests/test_SLinkedList.cpp)

# Link GoogleTest and pthread library to the test executable
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add tests to CTest
add_test(NAME SLinkedListTests COMMAND runTests)
