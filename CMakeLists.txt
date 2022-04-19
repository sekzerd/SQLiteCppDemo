cmake_minimum_required(VERSION 3.22)
set(PROJECT_NAME "SQLiteCppDemo")
set(CXX_EXTENSIONS 17)
project(${PROJECT_NAME})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs)

aux_source_directory("." SRCS)
add_executable(${PROJECT_NAME}_static_bin ${SRCS})
add_executable(${PROJECT_NAME}_dynamic_bin ${SRCS})

add_subdirectory("sqlite3")
target_link_libraries(${PROJECT_NAME}_static_bin SQLite3_static)
target_link_libraries(${PROJECT_NAME}_dynamic_bin SQLite3_shared)

file(COPY "sqlite3/libs/SQLite3_shared.dll" DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)