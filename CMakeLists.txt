cmake_minimum_required(VERSION 3.15)
project(hospital VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD 17) 

# Allows testing.
include(CTest)
enable_testing()

# Create a list of source files by globbing all .cpp files in "Testing/src" directory.
file(GLOB LIB_SOURCES "./src/*/*.cpp")

# Create a list of header files by globbing all .h or .hpp files in the "Testing/headers" directory and its subdirectories.
file(GLOB LIB_HEADERS "./headers/*/*.h" "./headers/*/*.hpp")

# Create the library target and specify the language as CXX (C++).
add_library(mylibrary ${LIB_SOURCES})
set_target_properties(mylibrary PROPERTIES LINKER_LANGUAGE CXX)

# Optionally, set an include directory for these headers.
target_include_directories(mylibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

# Add the header files to the library target (not mandatory but can be useful for IDEs).
target_sources(mylibrary PUBLIC ${LIB_HEADERS})

# Create an executable that uses the library.
add_executable(hospital_management main.cpp)

# Link the executable with the library.
target_link_libraries(hospital_management mylibrary)

# Specify the output directory for the executable.
set_target_properties(hospital_management PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output"
)