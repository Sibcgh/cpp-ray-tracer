cmake_minimum_required(VERSION 3.10)
project(CppRayTracer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include source files
file(GLOB SOURCES "src/*.cc")
include_directories(header)

# Add executable
add_executable(CppRayTracer ${SOURCES})

# Add a custom command to build, run the executable, and open the image file
add_custom_target(run
    COMMAND ./CppRayTracer > image.ppm && open image.ppm  # Run the executable and open the image
    DEPENDS CppRayTracer
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}  # Set working directory to build dir
    COMMENT "Building, running CppRayTracer, and opening image.ppm"
)

# Add a clean target to remove generated files
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove image.ppm  # Remove generated image
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}  # Remove build directory
    COMMENT "Cleaning up generated files"
)
