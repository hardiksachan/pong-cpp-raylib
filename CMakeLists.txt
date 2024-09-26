cmake_minimum_required(VERSION 3.10)
project(pong)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define paths for include and library directories
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/lib")

# Add include directories
include_directories(${INCLUDE_DIR})

# Link library
link_directories(${LIBRARY_DIR})

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link Raylib and required macOS frameworks
target_link_libraries(${PROJECT_NAME} raylib
    "-framework CoreVideo"
    "-framework IOKit"
    "-framework Cocoa"
    "-framework OpenGL"
)

# Print include and lib paths for debugging
message(STATUS "include directory: ${INCLUDE_DIR}")
message(STATUS "library directory: ${LIBRARY_DIR}")

