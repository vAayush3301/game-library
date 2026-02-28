#include "library/core/Application.h"
#include "library/core/Window.h"
#include "library/renderer/opengl/api/RenderCommand.h"

namespace gamelib::core {
    Application::Application(const ApplicationSpecification &spec) : m_Specification(spec) {
        m_Window = std::make_unique<Window>(
            m_Specification.Width,
            m_Specification.Height,
            m_Specification.Name
        );
    }

    Application::~Application() {

    }

    void Application::Run() {
        renderer::RenderCommand::Init();

        OnInit();

        while (!m_Window->ShouldClose()) {
            renderer::RenderCommand::SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            renderer::RenderCommand::Clear();

            OnUpdate(0.0f);

            m_Window->OnUpdate();
        }

        OnShutdown();
    }
}
