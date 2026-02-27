#include "../../../include/library/renderer/opengl/OpenGLRendererAPI.h"
#include <glad/glad.h>

namespace gamelib::renderer {
    void OpenGLRendererAPI::Init() {
        glEnable(GL_DEPTH_TEST);
    }

    void OpenGLRendererAPI::SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
    }

    void OpenGLRendererAPI::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}