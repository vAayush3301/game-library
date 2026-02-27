#include "library/core/Application.h"
#include "library/core/Window.h"

namespace gamelib::core {
    Application::Application() {
        m_Window = std::make_unique<Window>(800, 600, "GameLib");
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (m_running && !m_Window -> ShouldClose()) {
            m_Window -> OnUpdate();
        }
    }
}
