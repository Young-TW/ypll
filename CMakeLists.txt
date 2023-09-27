cmake_minimum_required(VERSION 3.20.0)
project(ypll VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 23)

find_package(LLVM REQUIRED CONFIG)

set(LLVM_ROOT "/usr/lib/llvm-14")

file(RELATIVE_PATH LEVEL ${PROJ_OBJ_ROOT} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})

include_directories(./include)

add_subdirectory(cxxopts)

file(GLOB_RECURSE SRC_FILES ./src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

llvm_map_components_to_libnames(llvm_libs core support)
target_link_libraries(${PROJECT_NAME} ${llvm_libs} cxxopts)
