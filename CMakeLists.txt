cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

project(ypll VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring for Linux")
    # Linux specific commands
    set(LLVM_ROOT "/usr/lib/llvm")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring for Windows")
    # Windows specific commands
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring for macOS")
    # macOS specific commands
    set(LLVM_ROOT "/opt/homebrew/opt/llvm")
    # set(DDEFAULT_SYSROOT "/path/to/MacOSX11.1.sdk")
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

include_directories(${LLVM_ROOT}/include)

find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(llvm_libs support core irreader)

file(RELATIVE_PATH LEVEL ${PROJ_OBJ_ROOT} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})

include_directories(./include)

add_subdirectory(cxxopts)

file(GLOB_RECURSE SRC_FILES ./src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} ${llvm_libs} cxxopts)
