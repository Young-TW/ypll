cmake_minimum_required(VERSION 3.20.0)
project(ypll VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_GENERATOR "Unix Makefiles")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

if("$ENV{ENVIRONMENT}" STREQUAL "macos")
    set(LLVM_ROOT "/opt/homebrew/opt/llvm")
elseif("$ENV{ENVIRONMENT}" STREQUAL "fedora")
    set(LLVM_ROOT "/usr/lib/llvm")
endif()

include_directories(${LLVM_ROOT}/include)

file(RELATIVE_PATH LEVEL ${PROJ_OBJ_ROOT} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})

include_directories(./include)

add_subdirectory(cxxopts)

file(GLOB_RECURSE SRC_FILES ./src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} ${LLVM_LIBRARIES} cxxopts)