#include "library/core/Window.h"
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

        m_NativeWindow = window;

        glfwMakeContextCurrent(window);
    }

    void Window::Shutdown() {
        glfwTerminate();
    }

    void Window::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers((GLFWwindow*)m_NativeWindow);
    }
}
