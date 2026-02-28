#include "glad/glad.h"
#include "library/core/Application.h"
#include "library/renderer/ElementBuffer.h"
#include "library/renderer/Renderer.h"
#include "library/renderer/Shader.h"
#include "library/renderer/VertexArray.h"

class Sandbox : public gamelib::core::Application {
public:
    using Application::Application;

protected:
    void OnInit() override;

    void OnUpdate(float dt) override;

private:
    std::unique_ptr<gamelib::renderer::VertexArray> m_VA;
    std::unique_ptr<gamelib::renderer::VertexBuffer> m_VB;
    std::unique_ptr<gamelib::renderer::Shader> m_Shader;
    std::unique_ptr<gamelib::renderer::ElementBuffer> m_EBO;
};

void Sandbox::OnInit() {
    float vertices[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f
    };

    uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0,
    };

    m_VA = std::make_unique<gamelib::renderer::VertexArray>();
    m_VA->Bind();

    m_VB = std::make_unique<gamelib::renderer::VertexBuffer>(vertices, sizeof(vertices));
    m_VA->AddBuffer(*m_VB);

    m_EBO = std::make_unique<gamelib::renderer::ElementBuffer>(indices, 6);

    std::string vertexSrc = R"(
                #version 330 core
                layout(location = 0) in vec2 aPos;

                void main()
                {
                    gl_Position = vec4(aPos, 0.0, 1.0);
                }
            )";

    std::string fragmentSrc = R"(
                #version 330 core
                out vec4 color;

                void main()
                {
                    color = vec4(1.0, 0.0, 0.0, 1.0);
                }
            )";

    m_Shader = std::make_unique<gamelib::renderer::Shader>(vertexSrc, fragmentSrc);
}

void Sandbox::OnUpdate(float dt) {
    m_Shader->Bind();
    gamelib::renderer::Renderer::DrawIndexed(*m_VA, m_EBO->GetCount());
}

int main() {
    gamelib::core::ApplicationSpecification spec;
    spec.Name = "Window";
    spec.Width = 1000;
    spec.Height = 800;

    Sandbox app(spec);
    app.Run();
}