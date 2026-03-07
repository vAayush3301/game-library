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

    void Renderer::DrawIndexed(const Mesh& mesh, Shader& shader) {
        shader.Bind();

        math::Transform2D transform_2d = mesh.GetTransform();
        const auto& model = transform_2d.GetMatrix();
        shader.SetMat4("u_Model", model.Data());

        mesh.Bind();
        glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
    }
}
