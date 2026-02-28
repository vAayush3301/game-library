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

    void Renderer::DrawIndexed(const VertexArray& vertexArray, uint32_t indexCount) {
        vertexArray.Bind();
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    }
}
