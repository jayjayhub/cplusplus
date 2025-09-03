# =============================================================================
# Improved CMakeLists.txt Template for Advanced C++ Learning
# Based on Udemy course template with professional enhancements
# =============================================================================

# Minimum CMake version (updated for better features)
cmake_minimum_required(VERSION 3.16)

# Smart project naming from directory
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 1.0 LANGUAGES CXX)

# =============================================================================
# C++ Standard Configuration
# =============================================================================

# Modern C++ standard (upgraded from C++11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

# =============================================================================
# Build Type Configuration
# =============================================================================

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Print build type for clarity
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# =============================================================================
# Output Directory Organization
# =============================================================================

# Organize build outputs (same as original)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =============================================================================
# Source File Discovery
# =============================================================================

# Find all source and header files
file(GLOB project_sources src/*.cpp src/*.cc)
file(GLOB project_headers src/*.h src/*.hpp)

# Optional: Print found files for debugging
message(STATUS "Found ${CMAKE_CURRENT_LIST_LENGTH} source files")

# =============================================================================
# Target Creation
# =============================================================================

# Create executable target
add_executable(${ProjectId} ${project_sources} ${project_headers})

# =============================================================================
# Compiler Configuration
# =============================================================================

# Enable comprehensive warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${ProjectId} PRIVATE
        -Wall           # Enable most warnings
        -Wextra         # Enable extra warnings
        -Wpedantic      # Strict standard compliance
        -Wconversion    # Warn on type conversions
        -Wshadow        # Warn on variable shadowing
        # -std=c++20      # Use C++20 standard
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${ProjectId} PRIVATE
        /W4             # High warning level
        /permissive-    # Strict standard compliance
    )
endif()

# =============================================================================
# Build Type Specific Settings
# =============================================================================

# Debug build configuration
target_compile_definitions(${ProjectId} PRIVATE
    $<$<CONFIG:Debug>:DEBUG_MODE>
    $<$<CONFIG:Debug>:_DEBUG>
)

# Release build optimization
target_compile_options(${ProjectId} PRIVATE
    $<$<CONFIG:Debug>:-g -O0>      # Debug symbols, no optimization
    $<$<CONFIG:Release>:-O3>       # Maximum optimization
)

# =============================================================================
# Include Directories (if you have them)
# =============================================================================

# Uncomment if you have an include/ directory
# target_include_directories(${ProjectId} PRIVATE include/)

# =============================================================================
# Future: External Libraries (Ready for Boost, MPI, etc.)
# =============================================================================

# Uncomment when you start using Boost:
# find_package(Boost REQUIRED COMPONENTS system filesystem)
# target_link_libraries(${ProjectId} ${Boost_LIBRARIES})
# target_include_directories(${ProjectId} PRIVATE ${Boost_INCLUDE_DIRS})

# Uncomment when you start using OpenMP:
# find_package(OpenMP REQUIRED)
# target_link_libraries(${ProjectId} OpenMP::OpenMP_CXX)

# Uncomment when you start using MPI:
# find_package(MPI REQUIRED)
# target_link_libraries(${ProjectId} MPI::MPI_CXX)

# =============================================================================
# Development Helpers
# =============================================================================

# Enable compile_commands.json for better IDE integration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set target properties for better debugging
set_target_properties(${ProjectId} PROPERTIES
    CXX_EXTENSIONS OFF
    POSITION_INDEPENDENT_CODE ON
)

# Print useful information
message(STATUS "Project: ${ProjectId}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")
message(STATUS "Source directory: ${CMAKE_SOURCE_DIR}")

# =============================================================================
# Optional: Testing Support (uncomment when needed)
# =============================================================================

# enable_testing()
# add_subdirectory(tests)