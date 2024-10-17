# Minimum CMake is 3.22
CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

# Set project name
PROJECT(
    cpp-python-interop
    VERSION 1.0.0
)

add_library(cpp-python-interop SHARED)

target_sources(
    cpp-python-interop
    PRIVATE src/main.cpp
)

# Set up regular, Release and Debug C flags
SET(CMAKE_CXX_FLAGS 
    "${CMAKE_CXX_FLAGS} \
    -Wall \
    -Werror \
    -Wextra \
    -fPIC")

target_compile_features(
    cpp-python-interop
    PUBLIC cxx_std_20
)

SET(CMAKE_RELEASE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -DNDEBUG -UDEBUG")
SET(CMAKE_RELEASE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -DNDEBUG -UDEBUG")

SET(CMAKE_DEBUG_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -DDEBUG -UNDEBUG")
SET(CMAKE_DEBUG_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -DDEBUG -UNDEBUG")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Set up debug postfix
SET_TARGET_PROPERTIES(cpp-python-interop 
    PROPERTIES VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
)
