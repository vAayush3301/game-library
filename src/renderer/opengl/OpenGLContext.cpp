#include "library/renderer/opengl/OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

namespace gamelib::renderer {
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle) {
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }

        std::cout << "OpenGL Info:" << std::endl;
        std::cout << "\tVendor:   " << glGetString(GL_VENDOR) << std::endl;
        std::cout << "\tRenderer: " << glGetString(GL_RENDERER) << std::endl;
        std::cout << "\tVersion:  " << glGetString(GL_VERSION) << std::endl;
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_WindowHandle);
    }
}
