#include "glad/glad.h"
#include "library/core/Application.h"
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
};

void Sandbox::OnInit() {
    float vertices[] = {
        0.0f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f,
    };

    m_VA = std::make_unique<gamelib::renderer::VertexArray>();
    m_VB = std::make_unique<gamelib::renderer::VertexBuffer>(vertices, sizeof(vertices));
    m_VA->AddBuffer(*m_VB);

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
    m_VA->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
    gamelib::core::ApplicationSpecification spec;
    spec.Name = "Window";
    spec.Width = 1000;
    spec.Height = 800;

    Sandbox app(spec);
    app.Run();
}
