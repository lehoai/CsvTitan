cmake_minimum_required (VERSION 3.8)

project(CSVTitanTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  CSVTitanTest
  csv_reader_test.cpp
 "csv_writer_test.cpp" "csv_sort_test.cpp"  "in_memory_sort_test.cpp" "data_table_test.cpp")


target_link_libraries(
  CSVTitanTest
  GTest::gtest_main
)

target_link_libraries(CSVTitanTest CSVTitan)

add_custom_command(TARGET CSVTitanTest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CSVTitan>
        $<TARGET_FILE_DIR:CSVTitanTest>
)

include(GoogleTest)
gtest_discover_tests(CSVTitanTest)

target_compile_definitions(CSVTitanTest PUBLIC CSV_FOLDER_DIR="${CMAKE_SOURCE_DIR}/tests/csv/")
target_compile_definitions(CSVTitanTest PUBLIC CSV_DATA_LARGE_FILE="${CMAKE_SOURCE_DIR}/tests/csv/large-data.csv")
target_compile_definitions(CSVTitanTest PUBLIC CSV_DATA_TEST_SORT="${CMAKE_SOURCE_DIR}/tests/csv/sort_test.csv")