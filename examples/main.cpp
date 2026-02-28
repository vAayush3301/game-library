#include "library/core/Application.h"
#include "library/renderer/VertexArray.h"

int main() {
    gamelib::core::ApplicationSpecification spec;
    spec.Name = "Window";
    spec.Width = 1000;
    spec.Height = 800;

    gamelib::core::Application app(spec);
    app.Run();

    float vertices[] = {
        0.0f, 0.5f,
        -0.5f, 0.5f,
        0.5f, -0.5f,
    };

    VertexArray va;
    VertexBuffer vb(vertices, sizeof(vertices));
    va.AddBuffer(vb);

    std::string vertexShader = R"(
                #version 330 core
                layout(location = 0) in vec2 aPos;

                void main()
                {
                    gl_Position = vec4(aPos, 0.0, 1.0);
                }
            )";

    std::string fragmentShader = R"(
                #version 330 core
                out vec4 color;

                void main()
                {
                    color = vec4(0.2, 0.6, 1.0, 1.0);
                }
            )";
}
