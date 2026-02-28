#pragma once

#include <memory>

namespace gamelib::renderer {
    class VertexArray;
    class VertexBuffer;
    class ElementBuffer;

    class Mesh {
    public:
        Mesh(float *vertices, uint32_t vertexSize, uint32_t *indices, uint32_t indexCount);

        void Bind() const;

        uint32_t GetIndexCount() const { return m_IndexCount; }

    private:
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<VertexBuffer> m_VBO;
        std::unique_ptr<ElementBuffer> m_EBO;

        uint32_t m_IndexCount;
    };
}