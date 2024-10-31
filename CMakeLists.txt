# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(CppRayTracer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include source files
file(GLOB SOURCES "src/*.cc")

# Add executable
add_executable(CppRayTracer ${SOURCES})

# Add a custom command to build and run the executable
add_custom_target(run
    COMMAND CppRayTracer
    DEPENDS CppRayTracer
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
    COMMENT "Building and running CppRayTracer"
)
