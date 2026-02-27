#include "library/renderer/opengl/api/RenderCommand.h"
#include "library/renderer/opengl/OpenGLRendererAPI.h"

namespace gamelib::renderer {
    std::unique_ptr<RendererAPI> RenderCommand::s_RendererAPI = std::make_unique<OpenGLRendererAPI>();

    void RenderCommand::Init() {
        s_RendererAPI->Init();
    }

    void RenderCommand::SetClearColor(float r, float g, float b, float a) {
        s_RendererAPI->SetClearColor(r, g, b, a);
    }

    void RenderCommand::Clear() {
        s_RendererAPI->Clear();
    }
}
