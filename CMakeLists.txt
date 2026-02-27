cmake_minimum_required(VERSION 3.15)
project(Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(library
        src/core.cpp
        src/glad.c
        src/math/vec2.cpp
        src/math/vec3.cpp
        src/math/vec4.cpp
        src/math/mat4.cpp
        src/camera/camera.cpp
        src/core/Application.cpp
        src/core/Window.cpp
        src/renderer/opengl/OpenGLRendererAPI.cpp
        src/renderer/opengl/OpenGLContext.cpp
        src/renderer/opengl/api/RenderCommand.cpp
)

target_include_directories(library PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(library PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
        opengl32
        gdi32
        user32
        shell32
)

add_executable(example examples/main.cpp)
target_link_libraries(example PRIVATE library)