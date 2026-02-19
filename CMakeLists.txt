cmake_minimum_required(VERSION 3.15)
project(Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(library
    src/core.cpp
    src/math/vec2.cpp
    src/math/vec3.cpp
    src/math/vec4.cpp
)

target_include_directories(library PUBLIC include)

add_executable(example examples/main.cpp)
target_link_libraries(example PRIVATE library)