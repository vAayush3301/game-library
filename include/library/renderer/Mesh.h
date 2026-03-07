#pragma once

#include <memory>
#include "library/math/transform.h"

namespace gamelib::renderer {
    class VertexArray;
    class VertexBuffer;
    class ElementBuffer;

    class Mesh {
    public:
        Mesh(float *vertices, uint32_t vertexSize, uint32_t *indices, uint32_t indexCount);

        void Bind() const;

        uint32_t GetIndexCount() const { return m_IndexCount; }

        gamelib::math::Transform2D GetTransform() { return m_Transform; }
        const gamelib::math::Transform2D GetTransform() const { return m_Transform; }

    private:
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<VertexBuffer> m_VBO;
        std::unique_ptr<ElementBuffer> m_EBO;

        uint32_t m_IndexCount;

        gamelib::math::Transform2D m_Transform;
    };
}