cmake_minimum_required (VERSION 3.8)

project (CSVTitan)
enable_testing()
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_library (CSVTitan
	SHARED 
	"includes/csv/CsvReader.h"
	"src/csv/CsvReader.cpp"
 "includes/csv/CsvWriter.h" "src/csv/CsvWriter.cpp" "includes/sort/CsvSort.h" "src/sort/CsvSort.cpp" "includes/sort/InMemorySort.h" "src/sort/MergeSort.cpp" "includes/utils/stringutils.h" "includes/sort/MergeSort.h" "src/sort/StandardInMemorySort.cpp" "includes/sort/StandardInMemorySort.h" "includes/utils/constant.h" "includes/join/CsvJoin.h" "src/join/CsvJoin.cpp" "includes/utils/DataTable.h" "src/utils/DataTable.cpp" "src/utils/stringutils.cpp")

# Set headers for the library
target_include_directories(CSVTitan PUBLIC ${CMAKE_SOURCE_DIR}/includes)

add_subdirectory(tests)

add_subdirectory(console)