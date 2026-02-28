#pragma once

#include "Mesh.h"
#include "Shader.h"

namespace gamelib::renderer {
    class Renderer {
    public:
        void Clear() const;

        void Draw(const VertexArray &va, const Shader &shader) const;

        static void DrawIndexed(const Mesh& mesh);
    };
}
