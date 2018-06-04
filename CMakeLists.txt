cmake_minimum_required (VERSION 2.6)
project (Example)

# Setting default folders
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# In CMakeModules I include code coverage for c++
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

include(CodeCoverage)
append_coverage_compiler_flags()

# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
if(NOT CMAKE_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread")

# Include header files
include_directories(src)

# include(CTest)
enable_testing()

# Include .cpp files
add_subdirectory(src)

# make coverage
set(COVERAGE_EXCLUDES "'/usr/*'")
setup_target_for_coverage(
    NAME coverage                               # New target name
    EXECUTABLE ${CMAKE_CTEST_COMMAND}           # Executable in PROJECT_BINARY_DIR
    DEPENDENCIES complex_test complex2_test     # Dependencies to build first
)
