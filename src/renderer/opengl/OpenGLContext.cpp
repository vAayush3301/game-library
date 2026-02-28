#include "library/renderer/opengl/OpenGLContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace gamelib::renderer {
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle) {
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);

        std::cout << "Current context: " << glfwGetCurrentContext() << std::endl;
        std::cout << "Window handle: " << m_WindowHandle << std::endl;

        std::cout << "Before" <<  std::endl;

        bool glad_load_gl_loader = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!glad_load_gl_loader) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            std::exit(-1);
        }

        std::cout << "After" <<  std::endl;

        std::cout << "GLAD loaded\n";
        std::cout << "glGetString ptr: " << (void*)glGetString << std::endl;

        std::cout << "OpenGL Info:" << std::endl;
        std::cout << "\tVendor:   " << glGetString(GL_VENDOR) << std::endl;
        std::cout << "\tRenderer: " << glGetString(GL_RENDERER) << std::endl;
        std::cout << "\tVersion:  " << glGetString(GL_VERSION) << std::endl;
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_WindowHandle);
    }
}
