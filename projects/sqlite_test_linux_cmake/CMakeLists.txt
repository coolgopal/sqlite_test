project(sqlite_test_linux_cmake)
cmake_minimum_required(VERSION 2.8)

#This is required for debugging
set(CMAKE_BUILD_TYPE Debug)

SET(PROJECT_SOURCE_DIR ../../src/)
SET(SQLITE_SOURCE_DIR ../../src/sqlite/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}
                    ${SQLITE_SOURCE_DIR})

aux_source_directory(../../src/sqlite/ SRC_LIST)
aux_source_directory(../../src/ SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PRIVATE -lpthread -ldl)
