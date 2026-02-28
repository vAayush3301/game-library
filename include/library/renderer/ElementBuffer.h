#pragma once

#include <cstdint>

namespace gamelib::renderer {
    class ElementBuffer {
    public:
        ElementBuffer(uint32_t *indices, uint32_t count);
        ~ElementBuffer();

        void Bind() const;
        void Unbind() const;

        uint32_t GetCount() const { return m_Count; }

    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}
