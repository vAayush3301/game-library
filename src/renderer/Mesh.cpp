#include "library/renderer/Mesh.h"
#include "library/renderer/VertexArray.h"
#include "library/renderer/VertexBuffer.h"
#include "library/renderer/ElementBuffer.h"

namespace gamelib::renderer {
    Mesh::Mesh(float *vertices, uint32_t vertexSize, uint32_t *indices, uint32_t indexCount) : m_IndexCount(indexCount) {
        m_VAO = std::make_unique<VertexArray>();
        m_VAO->Bind();

        m_VBO = std::make_unique<VertexBuffer>(vertices, vertexSize);
        m_VAO->AddBuffer(*m_VBO);

        m_EBO = std::make_unique<ElementBuffer>(indices, indexCount);
    }

    void Mesh::Bind() const {
        m_VAO->Bind();
    }
}