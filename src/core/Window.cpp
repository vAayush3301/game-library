#include "library/core/Window.h"
#include "library/renderer/opengl/OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace gamelib::core {
    Window::Window(unsigned int width, unsigned int height, const std::string &title) : m_width(width), m_height(height), m_Title(title) {
        Init();
    }

    Window::~Window() {
        Shutdown();
    }

    void Window::Init() {
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW!" << std::endl;
            return;
        }

        GLFWwindow* window = glfwCreateWindow(
            m_width,
            m_height,
            m_Title.c_str(),
            nullptr,
            nullptr
        );

        if (!window) {
            std::cout << "Failed to create GLFW window!" << std::endl;
            glfwTerminate();
            return;
        }

        m_NativeWindow = window;

        m_Context = std::make_unique<renderer::OpenGLContext>(window);
        m_Context->Init();
    }

    void Window::Shutdown() {
        if (m_NativeWindow) {
            glfwDestroyWindow((GLFWwindow*)m_NativeWindow);
            m_NativeWindow = nullptr;
        }
        glfwTerminate();
    }

    void Window::OnUpdate() {
        if (!m_NativeWindow || !m_Context) return;

        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose((GLFWwindow*)m_NativeWindow);
    }
}
