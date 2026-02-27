#include "library/core/Application.h"
#include "library/core/Window.h"

namespace gamelib::core {
    Application::Application(const ApplicationSpecification& spec) : m_Specification(spec) {
        m_Window = std::make_unique<Window>(
            m_Specification.Width,
            m_Specification.Height,
            m_Specification.Name
        );
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (m_Running && !m_Window -> ShouldClose()) {
            m_Window -> OnUpdate();
        }
    }
}
