cmake_minimum_required(VERSION 3.15)
project(Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GLFW_PATH ${CMAKE_SOURCE_DIR}/third_party/glfw)

set_source_files_properties(src/glad.c PROPERTIES LANGUAGE C)

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
        src/renderer/VertexBuffer.cpp
        src/renderer/VertexArray.cpp
        src/renderer/Renderer.cpp
        src/renderer/Shader.cpp
        src/renderer/ElementBuffer.cpp
        src/renderer/Mesh.cpp
)

target_include_directories(library PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${GLFW_PATH}/include
)

target_link_libraries(library PUBLIC
        ${GLFW_PATH}/build/src/libglfw3.a
        opengl32
        gdi32
        user32
        shell32
)

add_executable(example examples/main.cpp)
target_link_libraries(example PRIVATE library)