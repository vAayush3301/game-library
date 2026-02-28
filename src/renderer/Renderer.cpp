#include "library/renderer/Renderer.h"
#include <glad/glad.h>

#include "library/renderer/VertexArray.h"

namespace gamelib::renderer {
    void Renderer::Clear() const {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Draw(const VertexArray &va, const Shader &shader) const {
        shader.Bind();
        va.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}
