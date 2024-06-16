cmake_minimum_required (VERSION 3.8)
project(CSVTitanConsole)

add_executable(CSVTitanConsole "main.cpp")

target_link_libraries(CSVTitanConsole CSVTitan)

add_custom_command(TARGET CSVTitanConsole POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CSVTitan>
        $<TARGET_FILE_DIR:CSVTitanConsole>
)