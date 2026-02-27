#pragma once

#include "library/renderer/GraphicsContext.h"

struct GLFWwindow;

namespace gamelib::renderer {
    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        void Init() override;
        void SwapBuffers() override;

    private:
        GLFWwindow *m_WindowHandle;
    };
}
